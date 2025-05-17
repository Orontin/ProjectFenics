unit NewFile;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ComCtrls;

type
  TNewFileForm = class(TForm)
    btOk: TButton;
    btCancel: TButton;
    lbStreamsCount: TLabel;
    edStreamsCount: TEdit;
    lbLinesCount: TLabel;
    edLinesCount: TEdit;
    UpDownStreams: TUpDown;
    UpDownLines: TUpDown;
    rgFirstKnot: TRadioGroup;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure edLinesCountKeyPress(Sender: TObject; var Key: Char);
    procedure edStreamsCountKeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
  public
   procedure SetInterface;
  end;

var
  NewFileForm: TNewFileForm;

implementation

uses Main;

{$R *.dfm}

procedure TNewFileForm.edLinesCountKeyPress(Sender: TObject; var Key: Char);
begin
  case Key of
  '0'..'9': ;
  #8: ;
  else Key := Chr(0);
  end;
end;

procedure TNewFileForm.edStreamsCountKeyPress(Sender: TObject; var Key: Char);
begin
  case Key of
  '0'..'9': ;
  #8: ;
  else Key := Chr(0);
  end;
end;

procedure TNewFileForm.FormCreate(Sender: TObject);
begin
SetInterface;
end;

procedure TNewFileForm.FormShow(Sender: TObject);
begin
  edStreamsCount.Text := IntToStr(UpDownStreams.Position);
  edLinesCount.Text := IntToStr(UpDownLines.Position);
end;

procedure TNewFileForm.SetInterface;
begin
  Caption := strNewScheme;
  lbStreamsCount.Caption := strNumThreads;
  lbLinesCount.Caption := strNumRows;
  rgFirstKnot.Caption := strFirstKnot;
  rgFirstKnot.Items[0] := strThreads + ' 1 - 2';
  rgFirstKnot.Items[1] := strThreads + ' 2 - 3';
  btOk.Caption := strCreate;
  btCancel.Caption := strCancel;
  edLinesCount.Hint := strNumRowsHint;
  edStreamsCount.Hint := strNumThreadsHint;
end;

end.
