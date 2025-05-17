unit About;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ShellApi;

type
  TAboutForm = class(TForm)
    btOk: TButton;
    Label1: TLabel;
    Label2: TLabel;
    lbEMail: TLabel;
    lbLink: TLabel;
    procedure FormShow(Sender: TObject);
    procedure lbEMailClick(Sender: TObject);
    procedure lbLinkClick(Sender: TObject);
    procedure edEMailKeyPress(Sender: TObject; var Key: Char);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  AboutForm: TAboutForm;

implementation

uses Main;

{$R *.dfm}

procedure TAboutForm.edEMailKeyPress(Sender: TObject; var Key: Char);
begin
  Key := Chr(0);
end;

procedure TAboutForm.FormCreate(Sender: TObject);
begin
  AboutForm.Caption := strAbout;
end;

procedure TAboutForm.FormShow(Sender: TObject);
begin
  lbLink.Caption := strWithSupport;
end;

procedure TAboutForm.lbEMailClick(Sender: TObject);
begin
  ShellExecute(Application.Handle,'open',
              'mailto:braceletsdesigner@rambler.ru',nil,nil,SW_RESTORE);
end;

procedure TAboutForm.lbLinkClick(Sender: TObject);
begin
  keybd_event(VK_SHIFT,0,0,0);
  ShellExecute(0,'open','http://fene4ki.ru',nil,nil,SW_SHOW);
  keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
end;

end.
