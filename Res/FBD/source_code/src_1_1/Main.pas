unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Menus, StdCtrls, ComCtrls, ExtCtrls, Math, ActnMan, ActnColorMaps,
  Jpeg, ShellApi, Registry;

type
  TMainForm = class(TForm)
    MainMenu: TMainMenu;
    miFile: TMenuItem;
    miNew: TMenuItem;
    miOpen: TMenuItem;
    miSave: TMenuItem;
    miExport: TMenuItem;
    miLine: TMenuItem;
    miExit: TMenuItem;
    miHelp: TMenuItem;
    miAbout: TMenuItem;
    StatusBar: TStatusBar;
    gbScheme: TGroupBox;
    gbPreview: TGroupBox;
    sbScheme: TScrollBox;
    pbScheme: TPaintBox;
    pbPreview: TPaintBox;
    ColorDialog: TColorDialog;
    miScheme: TMenuItem;
    miAddLines: TMenuItem;
    miDelLines: TMenuItem;
    OpenDialog: TOpenDialog;
    SaveDialog: TSaveDialog;
    miOptions: TMenuItem;
    miShowPreview: TMenuItem;
    miClose: TMenuItem;
    miLanguage: TMenuItem;
    miEnglish: TMenuItem;
    miRussian: TMenuItem;
    SaveDialogExport: TSaveDialog;
    miOptimize: TMenuItem;
    procedure miOptimizeClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure miAboutClick(Sender: TObject);
    procedure miExportClick(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure miEnglishClick(Sender: TObject);
    procedure miRussianClick(Sender: TObject);
    procedure miCloseClick(Sender: TObject);
    procedure miShowPreviewClick(Sender: TObject);
    procedure miNewClick(Sender: TObject);
    procedure miOpenClick(Sender: TObject);
    procedure miSaveClick(Sender: TObject);
    procedure miExitClick(Sender: TObject);
    procedure miDelLinesClick(Sender: TObject);
    procedure miAddLinesClick(Sender: TObject);
    procedure pbSchemeMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure sbSchemeResize(Sender: TObject);
    procedure pbPreviewMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure pbSchemeMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure pbPreviewPaint(Sender: TObject);
    procedure pbSchemePaint(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  
  private
     procedure WMDropFiles(var Msg : TWMDropFiles); message WM_DROPFILES;

  public
   procedure SetLoaded(value : boolean);
   procedure SetInterface;
   procedure LoadENGLanguage;
   procedure LoadRUSLanguage;
   procedure LoadLanguage;
   procedure SaveLanguage;

  end;

var
  MainForm: TMainForm;
    strFile, strNew, strOpen, strSave, strExport, strClose, strExit,
    strPattern, strLengthen, strShorten,
    strOptions, strShowPreview, strLanguage,
    strHelp, strAbout,
    strChangeKnot, strZoom, strChangeColor,
    strPreview, strScheme,
    strNewScheme, strNumThreads, strNumRows,
    strFirstKnot, strThreads,
    strAttention, strNotSaved,
    strError, strFileSaveError, strFileLoadError,
    strCreate, strCancel,
    strNewHint, strOpenHint, strSaveHint, strCloseHint, strExportHint,
    strExitHint, strLengthenHint, strShortenHint, strAboutHint,
    strNumThreadsHint, strNumRowsHint, strOptimize, strOptimizeHint,
    strFBDfiles, strAllSupported, strJPEG, strWithSupport : string;


implementation

uses Scheme, NewFile, About;

{$R *.dfm}

var S : TScheme;
    bmpScheme, bmpPreview : TBitMap;
    SchemeLoaded, Saved : boolean;
    Language : string;


procedure TMainForm.miAboutClick(Sender: TObject);
begin
  AboutForm.ShowModal;
end;

procedure TMainForm.miAddLinesClick(Sender: TObject);
var xs, ys, xpv, ypv : integer;
begin
  S.AddLines;
  S.GetDimensions(xs, ys, xpv, ypv);
  bmpScheme.SetSize(xs, ys);
  pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
  pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
  S.Paint;
  S.PaintPreview;
  pbScheme.Repaint;
  pbPreview.Repaint;
  Saved := false;
end;

procedure TMainForm.miCloseClick(Sender: TObject);
begin
if (Saved)OR(MessageBox(Handle, PAnsiChar(strNotSaved),
              PAnsiChar(strAttention), MB_YESNO) = ID_YES) then
  begin
   SetLoaded(false);
   pbScheme.Repaint;
   pbPreview.Repaint;
   Saved := true;
  end;
end;

procedure TMainForm.miDelLinesClick(Sender: TObject);
var xs, ys, xpv, ypv : integer;
begin
  S.DelLines;
  S.GetDimensions(xs, ys, xpv, ypv);
  bmpScheme.SetSize(xs, ys);
  pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
  pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
  S.Paint;
  S.PaintPreview;
  pbScheme.Repaint;
  pbPreview.Repaint;
  Saved := false;
end;

procedure TMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  SaveLanguage;
end;

procedure TMainForm.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
if (NOT Saved)AND(MessageBox(Handle, PAnsiChar(strNotSaved),
  PAnsiChar(strAttention), MB_YESNO) = ID_NO) then
    CanClose := false;
end;

procedure TMainForm.FormCreate(Sender: TObject);
begin
  randomize;
  LoadLanguage;
  SetInterface;
  SetLoaded(false);
  Saved := true;
  S := TScheme.Create;
  S.SetView(7);
  S.SetPreview(5);
  bmpScheme := TBitMap.Create;
  bmpPreview := TBitMap.Create;
  S.SetCanvas(bmpScheme.Canvas);
  S.SetPreviewCanvas(bmpPreview.Canvas);
  DragAcceptFiles(Handle, true);
end;

procedure TMainForm.FormDestroy(Sender: TObject);
begin
  S.Destroy;
  bmpScheme.Free;
  bmpPreview.Free;
  DragAcceptFiles(Handle, false);
end;

procedure TMainForm.miEnglishClick(Sender: TObject);
begin
 if NOT miEnglish.Checked then
  begin
    miEnglish.Checked := true;
    miRussian.Checked := false;
    LoadENGLanguage;
    SetInterface;
    NewFileForm.SetInterface;
  end;
end;

procedure TMainForm.miExitClick(Sender: TObject);
begin
  MainForm.Close;
end;

procedure TMainForm.miExportClick(Sender: TObject);
var
  jpg : TJpegImage;
  bmp : TBitMap;
  xs, ys, xpv, ypv, Npv, R, Rpv, i, j : integer;
begin
  if SaveDialogExport.Execute then
    begin
      bmp := TBitMap.Create;
      Npv := S.Npv;
      R := S.R;
      Rpv := S.Rpv;
      S.SetView(7);
      S.SetPreview(5);
      S.GetDimensions(xs, ys, xpv, ypv);
      S.SetPreviewLines(floor((xs - 3*S.Rpv) / S.Rpv));
      S.GetDimensions(xs, ys, xpv, ypv);
      bmpPreview.SetSize(xpv, ypv);
      bmpScheme.SetSize(xs, ys);
      S.Paint;
      S.PaintPreview;
      bmp.SetSize(xs, xpv + ys);
      for i := 0 to bmpPreview.Height - 1 do
        for j := 0 to bmpPreview.Width - 1 do
          bmp.Canvas.Pixels[i,j] := bmpPreview.Canvas.Pixels[j,i];
      bmp.Canvas.CopyRect(Rect(0,xpv,xs,xpv+ys),
                                 bmpScheme.Canvas, Rect(0,0,xs,ys));
      jpg := TJpegImage.Create;
      jpg.Assign(bmp);
      jpg.SaveToFile(SaveDialogExport.FileName);
      jpg.Free;
      bmp.Free;
      S.SetPreviewLines(Npv);
      S.SetView(R);
      S.SetPreview(Rpv);
      S.GetDimensions(xs, ys, xpv, ypv);
      bmpPreview.SetSize(xpv, ypv);
      bmpScheme.SetSize(xs, ys);
      S.Paint;
      S.PaintPreview;
    end;
end;

procedure TMainForm.miNewClick(Sender: TObject);
var xs, ys, xpv, ypv : integer;
begin
if (Saved)OR(MessageBox(Handle, PAnsiChar(strNotSaved),
              PAnsiChar(strAttention), MB_YESNO) = ID_YES) then
 begin
  if NewFileForm.ShowModal = mrOk then
    begin
      SetLoaded(true);
      Saved := true;
      S.Reset(NewFileForm.UpDownLines.Position,
              NewFileForm.UpDownStreams.Position,
              (NewFileForm.rgFirstKnot.ItemIndex = 1));
      S.ChangeView(0);
      S.ChangePreview(0);
      S.GetDimensions(xs, ys, xpv, ypv);
      bmpScheme.SetSize(xs, ys);
      bmpPreview.SetSize(xpv, ypv);
      S.Paint;
      S.PaintPreview;
      gbPreview.Width := xpv + 20;
      if gbPreview.Width < 50 then
        gbPreview.Caption := '' else
        gbPreview.Caption := strPreview;
      pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
      pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
      pbScheme.Repaint;
      pbPreview.Repaint;
    end;
 end;
end;

procedure TMainForm.miOpenClick(Sender: TObject);
var xpv, ypv, xs, ys : integer;
begin
if (Saved)OR(MessageBox(Handle, PAnsiChar(strNotSaved),
              PAnsiChar(strAttention), MB_YESNO) = ID_YES) then
 begin
  if OpenDialog.Execute then
    begin
  if ((lowercase(extractfileext(OpenDialog.FileName))= '.fbd')AND
      (S.LoadFromFile(OpenDialog.FileName)))OR
      ((lowercase(extractfileext(OpenDialog.FileName))= '.rnx')AND
      (S.LoadFromRNXFile(OpenDialog.FileName))) then
     begin
       Saved := true;
       SetLoaded(true);
       S.GetDimensions(xs, ys, xpv, ypv);
       bmpPreview.SetSize(xpv, ypv);
       bmpScheme.SetSize(xs, ys);
       S.PaintPreview;
       S.Paint;
       gbPreview.Width := xpv + 20;
       if gbPreview.Width < 50 then
         gbPreview.Caption := '' else
         gbPreview.Caption := strPreview;
       pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
       pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
       pbScheme.Repaint;
       pbPreview.Repaint;
     end else
     begin
      MessageBox(Handle,PAnsiChar(strFileLoadError),
                          PAnsiChar(strError), MB_ICONERROR);
      SetLoaded(false);
     end;
    end;
 end;
end;

procedure TMainForm.miOptimizeClick(Sender: TObject);
var xs, ys, xpv, ypv : integer;
begin
 if S.Optimize then
   begin
      S.GetDimensions(xs, ys, xpv, ypv);
      bmpScheme.SetSize(xs, ys);
      pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
      pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
      S.Paint;
      S.PaintPreview;
      pbScheme.Repaint;
      pbPreview.Repaint;
      Saved := false;
   end;
end;

procedure TMainForm.miRussianClick(Sender: TObject);
begin
 if NOT miRussian.Checked then
  begin
    miEnglish.Checked := false;
    miRussian.Checked := true;
    LoadRUSLanguage;
    SetInterface;
    NewFileForm.SetInterface;
  end;
end;

procedure TMainForm.miSaveClick(Sender: TObject);
begin
 if SaveDialog.Execute then
  begin
    if S.SaveToFile(SaveDialog.FileName) then
    Saved := true else
     MessageBox(Handle,PAnsiChar(strFileSaveError),
                            PAnsiChar(strError), MB_ICONERROR);
  end;
end;

procedure TMainForm.miShowPreviewClick(Sender: TObject);
begin
  gbPreview.Visible := miShowPreview.Checked;
end;

procedure TMainForm.pbPreviewMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var d, xpv, ypv, a, b : integer;
begin
  if NOT SchemeLoaded then exit;
  if (button = mbLeft) then d := 1 else d := -1;
  S.ChangePreview(d);
  S.GetDimensions(a, b, xpv, ypv);
  bmpPreview.SetSize(xpv, ypv);
  S.PaintPreview;
  gbPreview.Width := xpv + 20;
  if gbPreview.Width < 50 then
    gbPreview.Caption := '' else
    gbPreview.Caption := strPreview;
  pbPreview.Repaint;
end;

procedure TMainForm.pbPreviewPaint(Sender: TObject);
var r: TRect;
    x, y, a, b : integer;
begin
  if NOT SchemeLoaded then exit;
  if S.Npv <> floor((gbPreview.Height - 45) / S.Rpv) then
    begin
      S.SetPreviewLines(floor((gbPreview.Height - 45) / S.Rpv));
      S.GetDimensions(a, b, x, y);
      bmpPreview.SetSize(x, y);
      S.PaintPreview;
    end;
  if pbPreview.Width <> bmpPreview.Width then
    pbPreview.Width := bmpPreview.Width;
  if pbPreview.Height <> bmpPreview.Height then
    pbPreview.Height := bmpPreview.Height;
  r := Rect(0,0,bmpPreview.Width,bmpPreview.Height);
  pbPreview.Canvas.CopyRect(r,bmpPreview.Canvas,r);
end;

procedure TMainForm.pbSchemeMouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
var a, b : integer;
    p : byte;
begin
  if NOT SchemeLoaded then exit;
  S.Click(x, y, a, b, p);
  case p of
    0: pbScheme.Hint := strChangeKnot;
    1, 2, 3, 4: pbScheme.Hint := strChangeColor;
    5: pbScheme.Hint := strZoom;
  end;
end;

procedure TMainForm.pbSchemeMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  i, j, a, b, xs, ys, d, line_number : integer;
  p : byte;
  color : TColor;
begin
  if NOT SchemeLoaded then exit;
  S.Click(x, y, i, j, p);
  case p of
    0:
      begin
       S.ShiftKnot(i, j, (button = mbRight));
       S.Paint;
       S.PaintPreview;
       pbScheme.Repaint;
       pbPreview.Repaint;
       Saved := false;
     end;
    1, 2, 3, 4:
      begin
        line_number := S.GetStreamNumber(i, j, p);
        if line_number < 0 then exit;
        if S.GetStreamColor(line_number, color) then
          ColorDialog.Color := color else
          ColorDialog.Color := clWhite;
        if ColorDialog.Execute then
          begin
            S.SetStreamColor(ColorDialog.Color, line_number);
            S.Paint;
            S.PaintPreview;
            pbScheme.Repaint;
            pbPreview.Repaint;
            Saved := false;
          end;
      end;
    5:
      begin
        if (button = mbLeft) then d := 1 else d := -1;
        S.ChangeView(d);
        S.GetDimensions(xs, ys, a, b);
        bmpScheme.SetSize(xs, ys);
        S.Paint;
        pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
        pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
        pbScheme.Repaint;
      end;
  end;
end;

procedure TMainForm.pbSchemePaint(Sender: TObject);
var r: TRect;
begin
  if NOT SchemeLoaded then exit;
  r := Rect(0,0,bmpScheme.Width,bmpScheme.Height);
  pbScheme.Canvas.CopyRect(r,bmpScheme.Canvas,r);
end;

procedure TMainForm.sbSchemeResize(Sender: TObject);
begin
  if NOT SchemeLoaded then exit;
  pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
  pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
end;

procedure TMainForm.SetLoaded(value: Boolean);
begin
  SchemeLoaded := value;
  miSave.Enabled := value;
  miExport.Enabled := value;
  miClose.Enabled := value;
  miAddLines.Enabled := value;
  miDelLines.Enabled := value;
  miOptimize.Enabled := value;
  if value then pbPreview.Hint := strZoom else
              begin
                pbPreview.Hint := '';
                pbScheme.Hint := '';
              end;
end;

procedure TMainForm.SetInterface;
begin
  miFile.Caption := strFile;
  miNew.Caption := strNew;
  miOpen.Caption := strOpen;
  miSave.Caption := strSave;
  miExport.Caption := strExport;
  miClose.Caption := strClose;
  miExit.Caption := strExit;
  miScheme.Caption := strPattern;
  miAddLines.Caption := strLengthen;
  miDelLines.Caption := strShorten;
  miOptions.Caption := strOptions;
  miShowPreview.Caption := strShowPreview;
  miLanguage.Caption := strLanguage;
  miHelp.Caption := strHelp;
  miAbout.Caption := strAbout;
  gbScheme.Caption := strScheme;
  gbPreview.Caption := strPreview;
  pbPreview.Hint := strZoom;
  miNew.Hint := strNewHint;
  miOpen.Hint := strOpenHint;
  miSave.Hint := strSaveHint;
  miExport.Hint := strExportHint;
  miClose.Hint := strCloseHint;
  miExit.Hint := strExitHint;
  miAddLines.Hint := strLengthenHint;
  miDelLines.Hint := strShortenHint;
  miAbout.Hint := strAboutHint;
  AboutForm.Caption := strAbout;
  miOptimize.Caption := strOptimize;
  miOptimize.Hint := strOptimizeHint;
  OpenDialog.Filter := strAllSupported;
  SaveDialog.Filter := strFBDfiles;
  SaveDialogExport.Filter := strJPEG;
end;

procedure TMainForm.LoadENGLanguage;
begin
  strAbout := 'About';
  strAttention := 'Attention';
  strChangeColor := 'Change color of thread';
  strChangeKnot := 'Change knot';
  strClose := 'Close';
  strError := 'Error';
  strExit := 'Exit';
  strExport := 'Export';
  strFile := 'File';
  strFileLoadError := 'Loading error';
  strFileSaveError := 'Saving error';
  strFirstKnot := 'First knot';
  strHelp := 'About';
  strLanguage := 'Language';
  strLengthen := 'Lengthen';
  strNew := 'New';
  strNewScheme := 'New project';
  strNotSaved := 'The file was not saved. Continue?';
  strNumRows := 'Number of rows';
  strNumThreads := 'Number of threads';
  strOpen := 'Open';
  strOptions := 'Options';
  strPattern := 'Pattern';
  strPreview := 'Preview';
  strSave := 'Save';
  strScheme := 'Pattern';
  strShorten := 'Shorten';
  strShowPreview := 'Show preview';
  strThreads := 'Threads';
  strZoom := 'Zoom in / Zoom out';
  strCreate := 'Create';
  strCancel := 'Cancel';
  strNewHint := 'Create new project';
  strOpenHint := 'Open existing project';
  strSaveHint := 'Save project';
  strExportHint := 'Save project as picture';
  strCloseHint := 'Close this project';
  strExitHint := '';
  strShortenHint := 'Delete two rows';
  strLengthenHint := 'Add two rows';
  strAboutHint := 'About Friendship Bracelet Desiner';
  strNumThreadsHint := 'Input value from 2 to 250';
  strNumRowsHint := 'Input value from 2 to 250';
  strOptimize := 'Optimize';
  strOptimizeHint := 'Delete duplicate samples';
  strFBDFiles := 'FBD files (*.fbd)|*.fbd';
  strAllSupported := 'All supported files (*.fbd; *.rnx)|*.fbd; *.rnx';
  strJPEG := 'JPEG files (*.jpg; *.jpeg)|*.jpg; *.jpeg';
  strWithSupport := 'With support of http://fene4ki.ru';
  Language := 'ENG';
end;

procedure TMainForm.LoadRUSLanguage;
begin
  strAbout := '� ���������';
  strAttention := '��������������';
  strChangeColor := '�������� ���� ����';
  strChangeKnot := '�������� ����';
  strClose := '�������';
  strError := '������';
  strExit := '�����';
  strExport := '�������';
  strFile := '����';
  strFileLoadError := '������ �������� �����';
  strFileSaveError := '������ ���������� �����';
  strFirstKnot := '������ ����';
  strHelp := '�������';
  strLanguage := '����';
  strLengthen := '��������';
  strNew := '�����';
  strNewScheme := '����� �����';
  strNotSaved := '���� �� ��� �������. ���������?';
  strNumRows := '���������� �����';
  strNumThreads := '���������� �����';
  strOpen := '�������';
  strOptions := '���������';
  strPattern := '�����';
  strPreview := '������';
  strSave := '���������';
  strScheme := '�������� �����';
  strShorten := '���������';
  strShowPreview := '���������� ������';
  strThreads := '����';
  strZoom := '���������� / ��������';
  strCreate := '�������';
  strCancel := '������';
  strNewHint := '������� ����� �����';
  strOpenHint := '������� ������������ �����';
  strSaveHint := '��������� �����';
  strExportHint := '��������� ����� ��� ��������';
  strCloseHint := '��������� ������ � �������� ������';
  strExitHint := '����� �� ���������';
  strShortenHint := '������� ��� ��������� ���� �������';
  strLengthenHint := '�������� ��� ���� �������';
  strAboutHint := '� ��������� Friendship Bracelet Desiner';
  strNumThreadsHint := '������� �������� �� 2 �� 250';
  strNumRowsHint := '������� �������� �� 2 �� 250';
  strOptimize := '������� �������';
  strOptimizeHint := '������� ������������� ��������� �����';
  strFBDFiles := 'FBD ����� (*.fbd)|*.fbd';
  strAllSupported := '��� �������������� ����� (*.fbd; *.rnx)|*.fbd; *.rnx';
  strJPEG := '����� JPEG (*.jpg; *.jpeg)|*.jpg; *.jpeg';
  strWithSupport := '��� ��������� http://fene4ki.ru';
  Language := 'RUS';
end;

procedure TMainForm.WMDropFiles(var Msg : TWMDropFiles);
var
  h : THandle;
  pchr : array [0..254] of char;
  fname : string;
  xpv, ypv, xs, ys : integer;
begin
  h := Msg.Drop;
  DragQueryFile(h, 0, pchr, 254);
  fname := string(pchr);
  if (lowercase(extractfileext(fname))<>'.fbd')AND
     (lowercase(extractfileext(fname))<>'.rnx') then exit;
  if (Saved)OR(MessageBox(Handle, PAnsiChar(strNotSaved),
              PAnsiChar(strAttention), MB_YESNO) = ID_YES) then
    begin
     if ((lowercase(extractfileext(fname))= '.fbd')AND
      (S.LoadFromFile(fname)))OR
      ((lowercase(extractfileext(fname))= '.rnx')AND
      (S.LoadFromRNXFile(fname))) then
        begin
          SetLoaded(true);
          Saved := true;
          S.GetDimensions(xs, ys, xpv, ypv);
          bmpPreview.SetSize(xpv, ypv);
          bmpScheme.SetSize(xs, ys);
          S.PaintPreview;
          S.Paint;
          gbPreview.Width := xpv + 20;
          if gbPreview.Width < 50 then
             gbPreview.Caption := '' else
             gbPreview.Caption := strPreview;
          pbScheme.Width := MAX(bmpScheme.Width, (gbScheme.Width - 4));
          pbScheme.Height := MAX(bmpScheme.Height, (gbScheme.Height - 17));
          pbScheme.Repaint;
          pbPreview.Repaint;
       end else
       begin
        MessageBox(Handle,PAnsiChar(strFileLoadError),
                            PAnsiChar(strError), MB_ICONERROR);
        SetLoaded(false);
       end;
    end;
end;

procedure TMainForm.LoadLanguage;
var
    Reg : TRegistry;
    lng : string;
begin
  Reg := TRegistry.Create(KEY_READ);
  try
    if Reg.OpenKey('Software\Friendship Bracelets Designer', false) then
      lng := Reg.ReadString('Language');
    if lng = 'RUS' then
      begin
       LoadRUSLanguage;
       miEnglish.Checked := false;
       miRussian.Checked := true;
      end else
      LoadENGLanguage;
  finally
    Reg.Free;
  end;
end;

procedure TMainForm.SaveLanguage;
var
    Reg : TRegistry;
begin
  Reg := TRegistry.Create(KEY_WRITE);
  try
    if Reg.OpenKey('Software\Friendship Bracelets Designer', true) then
      Reg.WriteString('Language', Language);
  finally
    Reg.Free;
  end;
end;

end.
