program FBD;

uses
  Forms,
  Main in 'Main.pas' {MainForm},
  Scheme in 'Scheme.pas',
  NewFile in 'NewFile.pas' {NewFileForm},
  About in 'About.pas' {AboutForm},
  PopUpForm in 'PopUpForm.pas' {fmPopup};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'Friendship Bracelets Designer';
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TNewFileForm, NewFileForm);
  Application.CreateForm(TAboutForm, AboutForm);
  Application.CreateForm(TfmPopup, fmPopup);
  Application.Run;
end.
