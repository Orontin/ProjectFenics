unit PopUpForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TfmPopup = class(TForm)
    lbGroups: TListBox;
    btDelete: TButton;
    btOK: TButton;
    btAdd: TButton;
    procedure lbGroupsDrawItem(Control: TWinControl; Index: Integer;
      Rect: TRect; State: TOwnerDrawState);
    procedure btOKClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure btDeleteClick(Sender: TObject);
    procedure btAddClick(Sender: TObject);
  private
    { Private declarations }
  public
    Thread : integer;
    procedure UpdateGroups;
  end;

var
  fmPopup: TfmPopup;
  IsChanged : boolean;
  index_before : integer;
implementation

uses Main;

{$R *.dfm}

procedure TfmPopup.btAddClick(Sender: TObject);
begin
  S.AddColorGroup;
  UpdateGroups;
  IsChanged := true;
end;

procedure TfmPopup.btDeleteClick(Sender: TObject);
begin
  if lbGroups.ItemIndex < 1 then exit;
  S.DelColorGroup(lbGroups.ItemIndex - 1);
  UpdateGroups;
  IsChanged := true;
end;

procedure TfmPopup.btOKClick(Sender: TObject);
begin
 if lbGroups.ItemIndex < 1 then S.DelThreadFromGroup(thread) else
  S.AddThreadToGroup(thread, lbGroups.ItemIndex-1);
 if (IsChanged)OR(index_before <> S.ThColorGr[Thread-1]) then
  ModalResult := mrOK else
  ModalResult := mrCancel;
end;

procedure TfmPopup.FormShow(Sender: TObject);
begin
 UpdateGroups;
 lbGroups.ItemIndex := S.ThColorGr[Thread-1] + 1;
 index_before := S.ThColorGr[Thread-1];
 btAdd.Caption := strCreate;
 btDelete.Caption := strDelete;
 Caption := strGrouping;
 IsChanged := false;
end;

procedure TfmPopup.lbGroupsDrawItem(Control: TWinControl; Index: Integer;
  Rect: TRect; State: TOwnerDrawState);
begin
 lbGroups.Canvas.Font.Color := clBlack;
 lbGroups.Canvas.Brush.Color := lbGroups.Color;
 lbGroups.Canvas.FillRect(Rect);
 if index = 0 then
  begin
    if (odSelected in State) then
    begin
      lbGroups.Canvas.Font.Color := clRed;
      lbGroups.Canvas.Font.Style := [fsBold];
    end;
    lbGroups.Canvas.TextOut(Rect.Left + 5, Rect.Top + 3, lbGroups.Items[index]);
  end else
  begin
    lbGroups.Canvas.Pen.Color := clBlack;
    if NOT S.ColorGroups[index-1].empty then
      lbGroups.Canvas.Brush.Color := S.ColorGroups[index-1].color else
     begin
      lbGroups.Canvas.Brush.Color := clBlack;
      lbGroups.Canvas.Brush.Style := bsDiagCross;
     end;
    lbGroups.Canvas.Pen.Color := clBlack;
    lbGroups.Canvas.Rectangle(Rect.Left + 2, Rect.Top + 2,
                              Rect.Left + 30, Rect.Bottom - 2);
    if (odSelected in State) then
    begin
      lbGroups.Canvas.Font.Color := clRed;
      lbGroups.Canvas.Font.Style := [fsBold];
    end;
    lbGroups.Canvas.Brush.Color := lbGroups.Color;
    lbGroups.Canvas.TextOut(Rect.Left + 35, Rect.Top + 3, lbGroups.Items[index]);
  end;
end;

procedure TfmPopup.UpdateGroups;
var
  i : integer;
begin
  lbGroups.Items.Clear;
  lbGroups.Items.Add(strEmpty);
  for i := 1 to S.NColorGroups do
    lbGroups.Items.Add(strGroup + ' ' + IntToStr(i));
  lbGroups.ItemIndex := S.ThColorGr[thread-1] + 1;
end;

end.
