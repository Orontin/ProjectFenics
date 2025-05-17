unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Menus, StdCtrls, ComCtrls, ExtCtrls, Math, ActnMan, ActnColorMaps,
  Jpeg, ShellApi, Registry, Scheme;

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
    N1: TMenuItem;
    miAddRThread: TMenuItem;
    miDelRThread: TMenuItem;
    miAddLThread: TMenuItem;
    miDelLThread: TMenuItem;
    miPanels: TMenuItem;
    N2: TMenuItem;
    miGroup: TMenuItem;
    miUngroup: TMenuItem;
    procedure miGroupClick(Sender: TObject);
    procedure miUngroupClick(Sender: TObject);
    procedure miDelLThreadClick(Sender: TObject);
    procedure miAddLThreadClick(Sender: TObject);
    procedure miDelRThreadClick(Sender: TObject);
    procedure miAddRThreadClick(Sender: TObject);
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
   procedure LoadRegData;
   procedure SaveRegData;
   procedure UpdateAll;
  end;

var
  MainForm: TMainForm;
  S : TScheme;
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
    strCreate, strCancel, strDelete,
    strNewHint, strOpenHint, strSaveHint, strCloseHint, strExportHint,
    strExitHint, strLengthenHint, strShortenHint, strAboutHint,
    strNumThreadsHint, strNumRowsHint, strOptimize, strOptimizeHint,
    strFBDfiles, strAllSupported, strJPEG, strWithSupport, strAddRThread,
    strDelRThread, strAddLThread, strDelLThread, strDefaultFileName,
    strPanels, strGrouping, strGroup, strEmpty,
    strToGroup, strToUngroup, strGroupHint, strUngroupHint : string;


implementation

uses {Scheme,} NewFile, About, PopUpForm;

{$R *.dfm}
const strName = 'Friendship Bracelets Designer';

var //S : TScheme;
    bmpScheme, bmpPreview : TBitMap;
    SchemeLoaded, Saved : boolean;
    Language, NowLoaded : string;


procedure TMainForm.miAboutClick(Sender: TObject);
begin
  AboutForm.ShowModal;
end;

procedure TMainForm.miAddLinesClick(Sender: TObject);
begin
  S.AddLines;
  UpdateAll;
  Saved := false;
end;

procedure TMainForm.miAddLThreadClick(Sender: TObject);
begin
  S.AddLThread;
  UpdateAll;
  Saved := false;
end;

procedure TMainForm.miAddRThreadClick(Sender: TObject);
begin
  S.AddRThread;
  UpdateAll;
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
begin
  S.DelLines;
  UpdateAll;
  Saved := false;
end;

procedure TMainForm.miDelLThreadClick(Sender: TObject);
begin
  S.DelLThread;
  UpdateAll;
  Saved := false;
end;

procedure TMainForm.miDelRThreadClick(Sender: TObject);
begin
  S.DelRThread;
  UpdateAll;
  Saved := false;
end;

procedure TMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  SaveRegData;
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
  SetLoaded(false);
  Saved := true;
  S := TScheme.Create;
{  S.SetView(7);
  S.SetPreview(5); }
  bmpScheme := TBitMap.Create;
  bmpPreview := TBitMap.Create;
  S.SetCanvas(bmpScheme.Canvas);
  S.SetPreviewCanvas(bmpPreview.Canvas);
  LoadRegData;
  SetInterface;
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

procedure TMainForm.miGroupClick(Sender: TObject);
begin
  S.GroupByColors;
  Saved := false;
end;



procedure TMainForm.miNewClick(Sender: TObject);
begin
if (Saved)OR(MessageBox(Handle, PAnsiChar(strNotSaved),
              PAnsiChar(strAttention), MB_YESNO) = ID_YES) then
 begin
  if NewFileForm.ShowModal = mrOk then
    begin
      NowLoaded := strDefaultFileName;
      SetLoaded(true);
      Saved := true;
      S.Reset(NewFileForm.UpDownLines.Position,
              NewFileForm.UpDownStreams.Position,
              (NewFileForm.rgFirstKnot.ItemIndex = 1));
      UpdateAll;
    end;
 end;
end;

procedure TMainForm.miOpenClick(Sender: TObject);
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
       NowLoaded := OpenDialog.FileName;
       SetLoaded(true);
       UpdateAll;
     end else
     begin
      MessageBox(Handle,PAnsiChar(strFileLoadError),
                          PAnsiChar(strError), MB_ICONERROR);
      SetLoaded(false);
     end;
    end;
 end;
 OpenDialog.FileName := '';
end;

procedure TMainForm.miOptimizeClick(Sender: TObject);
begin
 if S.Optimize then
   begin
      UpdateAll;
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
    begin
      Saved := true;
      NowLoaded := SaveDialog.FileName;
      SetLoaded(true);
    end
    else
     MessageBox(Handle,PAnsiChar(strFileSaveError),
                            PAnsiChar(strError), MB_ICONERROR);
  end;
end;

procedure TMainForm.miShowPreviewClick(Sender: TObject);
begin
  gbPreview.Visible := miShowPreview.Checked;
end;

procedure TMainForm.miUngroupClick(Sender: TObject);
begin
  S.ResetColorGroups;
  Saved := false;
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
        if Button = MBLEFT then
        begin
        if S.GetStreamColor(line_number, color) then
          ColorDialog.Color := color else
          ColorDialog.Color := clWhite;
        if ColorDialog.Execute then
          begin
            S.SetStreamColorWithGroup(ColorDialog.Color, line_number);
            S.Paint;
            S.PaintPreview;
            pbScheme.Repaint;
            pbPreview.Repaint;
            Saved := false;
          end;
        end else
        begin
          fmPopup.Left := Mouse.CursorPos.X;
          fmPopup.Top := Mouse.CursorPos.Y;
          fmPopup.Thread := line_number;
          if fmPopup.ShowModal = mrOk then
            begin
              S.Paint;
              S.PaintPreview;
              pbScheme.Repaint;
              pbPreview.Repaint;
              Saved := false;
            end;
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
  miAddRThread.Enabled := value;
  miDelRThread.Enabled := value;
  miAddLThread.Enabled := value;
  miDelLThread.Enabled := value;
  miGroup.Enabled := value;
  miUngroup.Enabled := value;
  if value then
              begin
               pbPreview.Hint := strZoom;
               Caption := ExtractFileName(NowLoaded) + ' - ' + StrName;
              end else
              begin
                NowLoaded := strDefaultFileName;
                pbPreview.Hint := '';
                pbScheme.Hint := '';
                Caption := strName;
              end;
 Application.Title := Caption;
 SaveDialog.FileName := ChangeFileExt(NowLoaded, '.fbd');
 SaveDialogExport.FileName := ChangeFileExt(NowLoaded, '.jpg');
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
  miAddRThread.Caption := strAddRThread;
  miDelRThread.Caption := strDelRThread;
  miAddLThread.Caption := strAddLThread;
  miDelLThread.Caption := strDelLThread;
  miPanels.Caption := strPanels;
  miGroup.Caption := strToGroup;
  miUngroup.Caption := strToUngroup;
  miGroup.Hint := strGroupHint;
  miUngroup.Hint := strUngroupHint;
  if NOT SchemeLoaded then
      NowLoaded := strDefaultFileName;
end;

procedure TMainForm.LoadENGLanguage;
begin
  strAbout := 'About';
  strAttention := 'Attention';
  strChangeColor := 'Change color of thread / To group';
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
  strShowPreview := 'Preview';
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
  strOptimizeHint := 'Delete duplicated samples';
  strFBDFiles := 'FBD files (*.fbd)|*.fbd';
  strAllSupported := 'All supported files (*.fbd; *.rnx)|*.fbd; *.rnx';
  strJPEG := 'JPEG files (*.jpg; *.jpeg)|*.jpg; *.jpeg';
  strWithSupport := 'With support of http://fene4ki.ru';
  strAddRThread := 'Add right thread';
  strDelRThread := 'Delete right thread';
  strAddLThread := 'Add left thread';
  strDelLThread := 'Delete left thread';
  strDefaultFileName := 'Untitled.fbd';
  strPanels := 'Panels';
  strGroup := 'Group';
  strEmpty := '< Without grouping >';
  strDelete := 'Delete';
  strGrouping := 'Groups';
  strToGroup := 'Group by color';
  strToUngroup := 'Ungroup';
  strGroupHint := 'Group all threads by color';
  strUngroupHint := 'Ungroup all threads';
  Language := 'ENG';
end;

procedure TMainForm.LoadRUSLanguage;
begin
  strAbout := 'О программе';
  strAttention := 'Предупреждение';
  strChangeColor := 'Изменить цвет нити / Группировать';
  strChangeKnot := 'Изменить узел';
  strClose := 'Закрыть';
  strError := 'Ошибка';
  strExit := 'Выход';
  strExport := 'Экспорт';
  strFile := 'Файл';
  strFileLoadError := 'Ошибка загрузки файла';
  strFileSaveError := 'Ошибка сохранения файла';
  strFirstKnot := 'Первый узел';
  strHelp := 'Справка';
  strLanguage := 'Язык';
  strLengthen := 'Продлить';
  strNew := 'Новый';
  strNewScheme := 'Новая схема';
  strNotSaved := 'Файл не был сохранён. Продожить?';
  strNumRows := 'Количество рядов';
  strNumThreads := 'Количество нитей';
  strOpen := 'Открыть';
  strOptions := 'Настройка';
  strPattern := 'Схема';
  strPreview := 'Фенька';
  strSave := 'Сохранить';
  strScheme := 'Фрагмент схемы';
  strShorten := 'Сократить';
  strShowPreview := 'Фенькa';
  strThreads := 'Нити';
  strZoom := 'Приблизить / Отдалить';
  strCreate := 'Создать';
  strCancel := 'Отмена';
  strNewHint := 'Создать новую схему';
  strOpenHint := 'Открыть существующую схему';
  strSaveHint := 'Сохранить схему';
  strExportHint := 'Сохранить схему как картинку';
  strCloseHint := 'Закончить работу с открытой схемой';
  strExitHint := 'Выйти из программы';
  strShortenHint := 'Удалить два последних ряда узелков';
  strLengthenHint := 'Добавить два ряда узелков';
  strAboutHint := 'О программе Friendship Bracelet Desiner';
  strNumThreadsHint := 'Введите значение от 2 до 250';
  strNumRowsHint := 'Введите значение от 2 до 250';
  strOptimize := 'Удалить повторы';
  strOptimizeHint := 'Удалить повторяющиеся фрагменты схемы';
  strFBDFiles := 'FBD файлы (*.fbd)|*.fbd';
  strAllSupported := 'Все поддерживаемые файлы (*.fbd; *.rnx)|*.fbd; *.rnx';
  strJPEG := 'Файлы JPEG (*.jpg; *.jpeg)|*.jpg; *.jpeg';
  strWithSupport := 'При поддержке http://fene4ki.ru';
  strAddRThread := 'Добавить нить справа';
  strDelRThread := 'Удалить нить справа';
  strAddLThread := 'Добавить нить слева';
  strDelLThread := 'Удалить нить слева';
  strDefaultFileName := 'Безымянный.fbd';
  strPanels := 'Панели';
  strGroup := 'Группа';
  strEmpty := '< Нет группы >';
  strDelete := 'Удалить';
  strGrouping := 'Группы';
  strToGroup := 'Группировать по цвету';
  strToUngroup := 'Разгруппировать';
  strGroupHint := 'Установить совместное изменение цвета ниток';
  strUngroupHint := 'Разгруппировать все нитки';
  Language := 'RUS';
end;

procedure TMainForm.WMDropFiles(var Msg : TWMDropFiles);
var
  h : THandle;
  pchr : array [0..254] of char;
  fname : string;
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
          NowLoaded := fname;
          SetLoaded(true);
          Saved := true;
          UpdateAll;
       end else
       begin
        MessageBox(Handle,PAnsiChar(strFileLoadError),
                            PAnsiChar(strError), MB_ICONERROR);
        SetLoaded(false);
       end;
    end;
end;

procedure TMainForm.LoadRegData;
var
    Reg : TRegistry;
    lng : string;
    show_pv : boolean;
    R, Rpv : integer;
begin
  Reg := TRegistry.Create(KEY_READ);
  try
    if Reg.OpenKey('Software\Friendship Bracelets Designer', false) then
    begin
      lng := Reg.ReadString('Language');
      try
      show_pv := Reg.ReadBool('Preview');
      except
      show_pv := true;
      end;
      try
      R := Reg.ReadInteger('R');
      except
      R := 7;
      end;
      try
      Rpv := Reg.ReadInteger('Rpv');
      except
      Rpv := 5;
      end;
    end;
    if (R < 2)OR(R > 12) then R := 7;
    if (Rpv < 1)OR(Rpv > 11) then Rpv := 5;
    S.SetView(R);
    S.SetPreview(Rpv);
    miShowPreview.Checked := show_pv;
    gbPreview.Visible := show_pv;
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

procedure TMainForm.SaveRegData;
var
    Reg : TRegistry;
begin
  Reg := TRegistry.Create(KEY_WRITE);
  try
    if Reg.OpenKey('Software\Friendship Bracelets Designer', true) then
    begin
      Reg.WriteString('Language', Language);
      Reg.WriteBool('Preview',miShowPreview.Checked);
      Reg.WriteInteger('R',S.R);
      Reg.WriteInteger('Rpv',S.Rpv);
    end;
  finally
    Reg.Free;
  end;
end;

procedure TMainForm.UpdateAll;
var xpv, ypv, xs, ys : integer;
begin
       S.ChangeView(0);
       S.ChangePreview(0);
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
end;

end.
