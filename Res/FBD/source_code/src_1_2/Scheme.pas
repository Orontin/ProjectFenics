unit Scheme;

interface

uses Classes, Graphics, Windows;

const NA = 1; RL = 2; LR = 3; RR =4; LL = 5;
      SR = 11; SL = 12; SRL = 13;
      FR = 21; FL = 22; FRL = 23;
      AR = 31; AL = 32; ZR = 0;
      STDB : array[1..4,1..10] of byte =
        ((SR,SL,FR,FRL,FL,ZR,AL,ZR,AR,NA),
         (ZR,SL,ZR,FR,FL,ZR,AL,ZR,ZR,AR),
         (SR,SRL,FR,FRL,FRL,FL,NA,AL,AR,NA),
         (ZR,SRL,ZR,FR,FRL,FL,NA,AL,ZR,AR));
      dy = 5;
      defaultColor = clWhite;

type TKnot = record
  InR, InL, OutR, OutL : TColor;
  bInR, bInL, bOutR, bOutL : boolean;
  value : byte;
end;

type TSchemeData = array of array of TKnot;

type TDoubleRow = array [1..2] of array of byte;

type TColorGroup = record
 color : TColor;
 empty :  boolean;
end;

type TColorGroups = array of TColorGroup;

type TThColorGr = array of integer;

type TScheme = class
  private
    d1, d2 : real;
    Canvas, PreviewCanvas : TCanvas;
    data, datapv : TSchemeData;
    N, M, dx, Nths : integer;
    SchemeType : byte;
    procedure UpdateKnot(SD : TSchemeData; x, y : integer);
    procedure SetInColors(SD : TSchemeData; x, y: integer);
    procedure PaintKnot(x, y : integer; knot : TKnot);
    procedure SetBrush(knot : TKnot; a : byte);
    function CalcClick(i, j, x, y : integer) : byte;
    function KnotColor(x, y : integer) : TColor;
    procedure UpdatePreview;
    function ConvertRNXKnot(k : byte) : byte;
    function CheckRNXDoubleRow(dblrow : TDoubleRow; j1, j2 : integer) : boolean;
    function OptimizeAt(OptN : integer) : boolean;
    procedure ChangeThreadsGroup(v0, v : integer);

  public
    ThColorGr : TThColorGr;
    R, Rpv, Npv, NColorGroups : integer;
    ColorGroups : TColorGroups;
    procedure Reset(lines, streams : integer; fullLeft : boolean);
    procedure Paint();
    procedure SetCanvas(c : TCanvas);
    procedure Click(x, y : integer; var i, j : integer; var p : byte);
    procedure ShiftKnot(x, y : integer; reverse : boolean);
    procedure ChangeView(d : integer);
    procedure ChangePreview(d : integer);
    procedure SetView(newR : integer);
    procedure SetPreview(newR : integer);
    procedure SetPreviewCanvas(c : TCanvas);
    procedure PaintPreview();
    procedure SetStreamColor(color : TColor; number : integer);
    function GetStreamNumber(x, y : integer; p : byte) : integer;
    procedure GetDimensions(var xsc, ysc, xpv, ypv : integer);
    procedure SetPreviewLines(Nlines : integer);
    procedure AddLines;
    procedure DelLines;
    function SaveToFile(fname : String) : boolean;
    function LoadFromFile(fname : String) : boolean;
    function LoadFromRNXFile(fname : String) : boolean;
    function GetStreamColor(number : integer; var color : TColor) : boolean;
    function Optimize : boolean;
    procedure AddRThread;
    procedure DelRThread;
    procedure AddLThread;
    procedure DelLThread;
    procedure AddThreadToGroup(th, gr : integer);
    procedure DelThreadFromGroup(th : integer);
    procedure AddColorGroup;
    procedure DelColorGroup(gr : integer);
    procedure SetStreamColorWithGroup(color : TColor; number : integer);
    procedure ResetColorGroups;
    procedure GroupByColors;
end;

implementation

procedure TScheme.Reset(lines: Integer; streams: Integer; fullLeft: Boolean);
var
  i, j : integer;
begin
  Nths := streams;
  SetLength(ThColorGr, Nths);
  ResetColorGroups;
  if (lines mod 2 = 1) then lines := lines + 1;
  N := lines + 1;
  if (fullLeft = false) AND (streams mod 2 = 0) then
    SchemeType := 1 else
  if (fullLeft = true) AND (streams mod 2 = 1) then
    SchemeType := 2 else
  if (fullLeft = false) AND (streams mod 2 = 1) then
    SchemeType := 3 else
  if (fullLeft = true) AND (streams mod 2 = 0) then
    SchemeType := 4;
  if (SchemeType = 2) then
    M := (streams div 2) + 1 else
    M := streams div 2;
  SetLength(data, N + 1);
  for i := 0 to N do
    SetLength(data[i], M + 1);
  for i := 1 to N - 1 do
    for j := 1 to M - 1 do
      data[i,j].value := NA;
  for j := 1 to M - 1 do
    begin
      data[0,j].value := SRL;
      data[N,j].value := FRL;
    end;
  data[0,0].value := STDB[SchemeType,1];
  data[0,M].value := STDB[SchemeType,2];
  if (N mod 2 = 0) then
    begin
       data[N,0].value := STDB[SchemeType,3];
       data[N,M].value := STDB[SchemeType,5];
    end else
    begin
       data[N,0].value := STDB[SchemeType,4];
       data[N,M].value := STDB[SchemeType,6];
    end;
  for i := 1 to N - 1 do
    begin
      if (i mod 2 = 0) then
        begin
          data[i,0].value := STDB[SchemeType,9];
          data[i,M].value := STDB[SchemeType,7];
        end else
        begin
          data[i,0].value := STDB[SchemeType,10];
          data[i,M].value := STDB[SchemeType,8];
        end;
    end;
  for i := 0 to N do
    for j := 0 to M do
      begin
        data[i,j].bInR := false;
        data[i,j].bInL := false;
        UpdateKnot(data, i, j);
      end;
end;

procedure TScheme.UpdateKnot(SD : TSchemeData; x: Integer; y: Integer);
begin
  SetInColors(SD, x, y);
  case SD[x,y].value of
  RR, LL, AR, AL, SR,
  SL, SRL, FR, FL, FRL :
     begin
        SD[x,y].bOutR := SD[x,y].bInR;
        SD[x,y].bOutL := SD[x,y].bInL;
        if SD[x,y].bInR then SD[x,y].OutR := SD[x,y].InR;
        if SD[x,y].bInL then SD[x,y].OutL := SD[x,y].InL;
     end;
  RL, LR :
    begin
        SD[x,y].bOutR := SD[x,y].bInL;
        SD[x,y].bOutL := SD[x,y].bInR;
        if SD[x,y].bInR then SD[x,y].OutL := SD[x,y].InR;
        if SD[x,y].bInL then SD[x,y].OutR := SD[x,y].InL;
    end;
  NA, ZR :
    begin
     SD[x,y].bOutR := false;
     SD[x,y].bOutL := false;
    end;
  end;
end;

procedure TScheme.SetInColors(SD : TSchemeData; x: Integer; y: Integer);
begin
  if (x = 0) then
    begin
      case SD[x,y].value of
        ZR: begin
              SD[x,y].bInL := false;
              SD[x,y].bInR := false;
            end;
        SR: SD[x,y].bInL := false;
        SL: SD[x,y].bInR := false;
      end;
    end;
  if (x = 0) OR (SD[x,y].value = ZR) then exit;
  if (SD[x,y].value = RR)OR(SD[x,y].value = LL)OR
     (SD[x,y].value = RL)OR(SD[x,y].value = LR)OR
     (SD[x,y].value = NA)OR(SD[x,y].value = FRL) then
           begin
              if x mod 2 = 1 then
                begin
                 SD[x,y].bInR := SD[x-1,y+1].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y+1].OutL;
                 SD[x,y].bInL := SD[x-1,y].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y].OutR;
                end else
                begin
                 SD[x,y].bInR := SD[x-1,y].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y].OutL;
                 SD[x,y].bInL := SD[x-1,y-1].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y-1].OutR;
                end;
           end else
  begin
  case SchemeType of
  1 : begin
        case SD[x,y].value of
          AR, FR : begin
                 SD[x,y].bInR := SD[x-1,y].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y].OutL;
               end;
          AL, FL : begin
                 SD[x,y].bInL := SD[x-1,y-1].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y-1].OutR;
               end;
         end;
      end;  // 1
  2 : begin
        case SD[x,y].value of
          AR, FR : begin
                 SD[x,y].bInR := SD[x-1,y+1].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y+1].OutL;
               end;
          AL, FL : begin
                 SD[x,y].bInL := SD[x-1,y-1].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y-1].OutR;
               end;
        end;
      end;  //2
  3 : begin
        case SD[x,y].value of
          AR, FR : begin
                 SD[x,y].bInR := SD[x-1,y].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y].OutL;
               end;
          AL, FL : begin
                 SD[x,y].bInL := SD[x-1,y].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y].OutR;
               end;
         end;
      end;  //3
  4 : begin
        case SD[x,y].value of
          AR, FR : begin
                 SD[x,y].bInR := SD[x-1,y+1].bOutL;
                 if (SD[x,y].bInR) then SD[x,y].InR := SD[x-1,y+1].OutL;
               end;
          AL, FL : begin
                 SD[x,y].bInL := SD[x-1,y].bOutR;
                 if (SD[x,y].bInL) then SD[x,y].InL := SD[x-1,y].OutR;
               end;
        end;
      end; //4
  end;  //case SchemeType
 end;
end;

procedure TScheme.Paint();
var i, j : integer;
begin
Canvas.Pen.Width := 1 + (R div 7);
Canvas.Brush.Color := clWhite;
Canvas.FillRect(Canvas.ClipRect);
for i := 0 to N do
  for j := 0 to M do
    if i mod 2 = 0 then
      PaintKnot(j*10*R - dx, i*5*R + dy, data[i,j]) else
      PaintKnot(j*10*R + 5*R - dx, i*5*R + dy, data[i,j]);
end;

procedure TScheme.PaintKnot(x: Integer; y: Integer; knot: TKnot);
begin
{//---------
Canvas.Pen.Width := 1;
Canvas.MoveTo(x,y+5*R);
Canvas.LineTo(x+10*R,y+5*R);
Canvas.LineTo(x+10*R,y);
Canvas.Pen.Width := 1 + (R div 7);
//--------- }
  case knot.value of
  SL:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+R,y+5*R),Point(x+2*R,y+4*R),Point(x+2*R,y),
                   Point(x+4*R,y),Point(x+4*R,y+4*R),Point(x+3*R,y+5*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+R,y+5*R);
          LineTo(x+2*R,y+4*R);
          LineTo(x+2*R,y);
          LineTo(x+4*R,y);
          LineTo(x+4*R,y+4*R);
          LineTo(x+3*R,y+5*R);
        end;
    end;  // SL
  SR:
    begin
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+7*R,y+5*R),Point(x+6*R,y+4*R),Point(x+6*R,y),
                   Point(x+8*R,y),Point(x+8*R,y+4*R),Point(x+9*R,y+5*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+7*R,y+5*R);
          LineTo(x+6*R,y+4*R);
          LineTo(x+6*R,y);
          LineTo(x+8*R,y);
          LineTo(x+8*R,y+4*R);
          LineTo(x+9*R,y+5*R)
        end;
    end;  // SR
  SRL:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+R,y+5*R),Point(x+2*R,y+4*R),Point(x+2*R,y),
                   Point(x+4*R,y),Point(x+4*R,y+4*R),Point(x+3*R,y+5*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+R,y+5*R);
          LineTo(x+2*R,y+4*R);
          LineTo(x+2*R,y);
          LineTo(x+4*R,y);
          LineTo(x+4*R,y+4*R);
          LineTo(x+3*R,y+5*R);
        end;
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+7*R,y+5*R),Point(x+6*R,y+4*R),Point(x+6*R,y),
                   Point(x+8*R,y),Point(x+8*R,y+4*R),Point(x+9*R,y+5*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+7*R,y+5*R);
          LineTo(x+6*R,y+4*R);
          LineTo(x+6*R,y);
          LineTo(x+8*R,y);
          LineTo(x+8*R,y+4*R);
          LineTo(x+9*R,y+5*R)
        end;
    end;  // SRL
  FL:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+2*R,y),Point(x+2*R,y+4*R),
                   Point(x+4*R,y+4*R),Point(x+4*R,y)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+2*R,y);
          LineTo(x+2*R,y+4*R);
          LineTo(x+4*R,y+4*R);
          LineTo(x+4*R,y);
        end;
    end;  // FL
  FR:
    begin
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+6*R,y),Point(x+6*R,y+4*R),
                   Point(x+8*R,y+4*R),Point(x+8*R,y)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+6*R,y);
          LineTo(x+6*R,y+4*R);
          LineTo(x+8*R,y+4*R);
          LineTo(x+8*R,y);
        end;
    end; // FR
  FRL:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+2*R,y),Point(x+2*R,y+4*R),
                   Point(x+4*R,y+4*R),Point(x+4*R,y)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+2*R,y);
          LineTo(x+2*R,y+4*R);
          LineTo(x+4*R,y+4*R);
          LineTo(x+4*R,y);
        end;
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+6*R,y),Point(x+6*R,y+4*R),
                   Point(x+8*R,y+4*R),Point(x+8*R,y)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+6*R,y);
          LineTo(x+6*R,y+4*R);
          LineTo(x+8*R,y+4*R);
          LineTo(x+8*R,y);
        end;
    end; // FRL
  AR:
    begin
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+6*R,y),Point(x+8*R,y),Point(x+6*R,y+2*R),
                   Point(x+9*R,y+5*R),Point(x+7*R,y+5*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+6*R,y);
          LineTo(x+4*R,y+2*R);
          LineTo(x+7*R,y+5*R);
          MoveTo(x+8*R,y);
          LineTo(x+6*R,y+2*R);
          LineTo(x+9*R,y+5*R);
        end;
    end; // AR
   AL:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+2*R,y),Point(x+4*R,y),Point(x+6*R,y+2*R),
                   Point(x+3*R,y+5*R),Point(x+R,y+5*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+2*R,y);
          LineTo(x+4*R,y+2*R);
          LineTo(x+R,y+5*R);
          MoveTo(x+4*R,y);
          LineTo(x+6*R,y+2*R);
          LineTo(x+3*R,y+5*R);
        end;
    end;  // AL
   LR, RL, RR, LL, NA:
    begin
      SetBrush(knot, 1);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+2*R,y),Point(x+4*R,y),
                   Point(x+6*R,y+2*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+2*R,y);
          LineTo(x+4*R,y+2*R);
          MoveTo(x+4*R,y);
          LineTo(x+6*R,y+2*R);
        end;
      SetBrush(knot, 2);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+6*R,y),Point(x+8*R,y),
                   Point(x+6*R,y+2*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+6*R,y);
          LineTo(x+4*R,y+2*R);
          MoveTo(x+8*R,y);
          LineTo(x+6*R,y+2*R);
        end;
      SetBrush(knot, 3);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+R,y+5*R),Point(x+3*R,y+5*R),
                   Point(x+6*R,y+2*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+R,y+5*R);
          LineTo(x+4*R,y+2*R);
          MoveTo(x+3*R,y+5*R);
          LineTo(x+6*R,y+2*R);
        end;
      SetBrush(knot, 4);
      with Canvas do
        begin
          Canvas.Pen.Style := psClear;
          Polygon([Point(x+7*R,y+5*R),Point(x+9*R,y+5*R),
                   Point(x+6*R,y+2*R),Point(x+4*R,y+2*R)]);
          Canvas.Pen.Color := clBlack;
          Canvas.Pen.Style := psSolid;
          MoveTo(x+7*R,y+5*R);
          LineTo(x+4*R,y+2*R);
          MoveTo(x+9*R,y+5*R);
          LineTo(x+6*R,y+2*R);
        end;
      case knot.value of
        LR:
          begin
            SetBrush(knot,1);
            Canvas.Ellipse(x+3*R,y,x+7*R,y+4*R);
            Canvas.MoveTo(x+4*R,y+R);
            Canvas.LineTo(x+6*R,y+3*R);
            Canvas.LineTo(round(x+6*R-d2),round(y+3*R-d1));
            Canvas.MoveTo(x+6*R,y+3*R);
            Canvas.LineTo(round(x+6*R-d1),round(y+3*R-d2));
          end;
        RL:
          begin
            SetBrush(knot,2);
            Canvas.Ellipse(x+3*R,y,x+7*R,y+4*R);
            Canvas.MoveTo(x+6*R,y+R);
            Canvas.LineTo(x+4*R,y+3*R);
            Canvas.LineTo(round(x+4*R+d2),round(y+3*R-d1));
            Canvas.MoveTo(x+4*R,y+3*R);
            Canvas.LineTo(round(x+4*R+d1),round(y+3*R-d2));
          end;
        LL:
          begin
            SetBrush(knot,1);
            Canvas.Ellipse(x+3*R,y,x+7*R,y+4*R);
            Canvas.MoveTo(x+4*R,y+R);
            Canvas.LineTo(x+5*R,y+2*R);
            Canvas.LineTo(x+4*R,y+3*R);
            Canvas.LineTo(round(x+4*R+d2),round(y+3*R-d1));
            Canvas.MoveTo(x+4*R,y+3*R);
            Canvas.LineTo(round(x+4*R+d1),round(y+3*R-d2));
          end;
        RR:
          begin
            SetBrush(knot,2);
            Canvas.Ellipse(x+3*R,y,x+7*R,y+4*R);
            Canvas.MoveTo(x+6*R,y+R);
            Canvas.LineTo(x+5*R,y+2*R);
            Canvas.LineTo(x+6*R,y+3*R);
            Canvas.LineTo(round(x+6*R-d2),round(y+3*R-d1));
            Canvas.MoveTo(x+6*R,y+3*R);
            Canvas.LineTo(round(x+6*R-d1),round(y+3*R-d2));
          end;
        NA:
          begin
            SetBrush(knot,0);
            Canvas.Ellipse(x+3*R,y,x+7*R,y+4*R);
          end;
      end;
    end;  //  LR, RL, RR, LL, NA
  end; // case
end;

procedure TScheme.SetBrush(knot: TKnot; a: Byte);
begin
  case a of
    0: begin
        Canvas.Brush.Color := defaultColor;
        end; // 0
    1: begin
        if knot.bInL then
          begin
            Canvas.Brush.Color := knot.InL;
          end else
          begin
            Canvas.Brush.Color := defaultColor;
          end;
       end; // 1
     2: begin
        if knot.bInR then
          begin
            Canvas.Brush.Color := knot.InR;
          end else
          begin
            Canvas.Brush.Color := defaultColor;
          end;
       end; // 2
      3: begin
        if knot.bOutL then
          begin
            Canvas.Brush.Color := knot.OutL;
          end else
          begin
            Canvas.Brush.Color := defaultColor;
          end;
       end; // 3
      4: begin
        if knot.bOutR then
          begin
            Canvas.Brush.Color := knot.OutR;
          end else
          begin
            Canvas.Brush.Color := defaultColor;
          end;
       end; //4
  end; //case
end;

procedure TScheme.SetCanvas(c: TCanvas);
begin
  Canvas := c;
end;

procedure TScheme.Click(x: Integer; y: Integer;
                        var i: Integer; var j: Integer; var p: Byte);
begin
 y := y - dy;
 x := x + dx;
 i:= y div (5*R);
 if i mod 2 = 0 then
  begin
   j := x div (10*R);
   p := CalcClick(i, j, x-j*10*R, y-i*5*R);
  end else
  begin
   j := (x-5*R) div (10*R);
   p := CalcClick(i, j, x-j*10*R-5*R, y-i*5*R);
  end;
end;

function TScheme.CalcClick(i, j, x, y : integer) : byte;
begin
  result := 5;
  if (i > N)OR(j > M)OR(x < 0) then exit;
  case data[i,j].value of
    NA, RL, LR, RR, LL :
      begin
        result := 5;
        if (ABS(x+y-7*R) <= R) then
          begin
            if y < 2*R then result := 2 else
                            result := 3;
          end;
        if (ABS(x-y-3*R) <= R) then
          begin
            if y < 2*R then result := 1 else
                            result := 4;
          end;
        if (SQRT((x-5*R)*(x-5*R)+(y-2*R)*(y-2*R)) <= 2*R) then
          result := 0;
      end;
    SL:
      begin
        if (y<=4*R)AND(ABS(x-3*R)<=R)OR((y>4*R)AND(ABS(x+y-7*R)<=R))
          then result := 3;
      end;
    SR:
      begin
        if (y<=4*R)AND(ABS(x-7*R)<=R)OR((y>4*R)AND(ABS(x-y-3*R)<=R))
          then result := 4;
      end;
    SRL:
      begin
        if (y<=4*R)AND(ABS(x-3*R)<=R)OR((y>4*R)AND(ABS(x+y-7*R)<=R))
          then result := 3;
        if (y<=4*R)AND(ABS(x-7*R)<=R)OR((y>4*R)AND(ABS(x-y-3*R)<=R))
          then result := 4;
      end;
    FR:
      begin
        if (y<=4*R)AND(ABS(x-7*R)<=R) then result := 2;
      end;
    FL:
      begin
        if (y<=4*R)AND(ABS(x-3*R)<=R) then result := 1;
      end;
    FRL:
      begin
        if (y<=4*R)AND(ABS(x-7*R)<=R) then result := 2;
        if (y<=4*R)AND(ABS(x-3*R)<=R) then result := 1;
      end;
    AL:
      begin
        if (y<=2*R)AND((ABS(x-y-3*R)<=R))OR((y>2*R)AND(ABS(x+y-7*R)<=R)) then
          result := 1;
      end;
    AR:
      begin
        if (y<=2*R)AND((ABS(x+y-7*R)<=R))OR((y>2*R)AND(ABS(x-y-3*R)<=R)) then
          result := 2;
      end;
  end;
end;

procedure TScheme.ShiftKnot(x: Integer; y: Integer; reverse : boolean);
var
  i, j : integer;
begin
  if reverse then
  begin
   case data[x,y].value of
     LL: data[x,y].value := LR;
     RL: data[x,y].value := RR;
     RR: data[x,y].value := LL;
     NA: data[x,y].value := RL;
     LR: data[x,y].value := NA;
   end;
  end else
  begin
   case data[x,y].value of
     LR: data[x,y].value := LL;
     LL: data[x,y].value := RR;
     RL: data[x,y].value := NA;
     RR: data[x,y].value := RL;
     NA: data[x,y].value := LR;
   end;
  end;
  for i := x to N do
    for j := 0 to M do
      UpdateKnot(data, i, j);
end;

procedure TScheme.ChangeView(d: Integer);
begin
  if (R+d > 2)AND(R+d < 12) then SetView(R+d);
end;

procedure TScheme.SetView(newR: Integer);
begin
  R := newR;
  d1 := 0.2*R;
  d2 := 1.0*R;
  if (SchemeType = 2)OR(SchemeType = 4) then
  dx := 6*R else
  dx := 0;
end;

procedure TScheme.SetPreviewCanvas(c: TCanvas);
begin
  PreviewCanvas := c;
end;

procedure TScheme.PaintPreview();
var
  i, j, d, x, y, x0 : integer;
begin
  UpdatePreview;
  PreviewCanvas.Brush.Color:=clWhite;
  PreviewCanvas.FillRect(PreviewCanvas.ClipRect);
  if Rpv < 3  then PreviewCanvas.Pen.Style := psClear else
                   PreviewCanvas.Pen.Style := psSolid;
  if (SchemeType = 2)OR(SchemeType = 4) then
    x0 := 0 - Rpv else
    x0 := 0;
    for i := 1 to Npv do
    for j := 0 to M do
      begin
      if (datapv[i,j].value = NA)OR(datapv[i,j].value = RR)OR
         (datapv[i,j].value = LL)OR(datapv[i,j].value = RL)OR
         (datapv[i,j].value = LR) then
          begin
            if (i mod 2 = 0) then d := Rpv else d := 0;
            x := j*2*Rpv - d + x0;
            y := 5 + i*Rpv;
            PreviewCanvas.Brush.Color := KnotColor(i, j);
            PreviewCanvas.Polygon([Point(x,y),
                                   Point(x+Rpv,y-Rpv),
                                   Point(x+2*Rpv,y),
                                   Point(x+Rpv,y+Rpv)]);
          end;
      end;
end;

function TScheme.KnotColor(x: Integer; y: Integer) : TColor;
begin
  result := defaultColor;
  case datapv[x,y].value of
  RL, RR : if datapv[x,y].bInR then result := datapv[x,y].InR;
  LR, LL : if datapv[x,y].bInL then result := datapv[x,y].InL;
  end;
end;

procedure TScheme.SetStreamColor(color: TColor; number: Integer);
var
  i, j : integer;
begin
  if (SchemeType = 1)OR(SchemeType = 3) then
    begin
      j := number div 2;
      if (number mod 2 = 0) then
        begin
          data[0,j].bInL := true;
          data[0,j].InL := color;
        end else
        begin
          data[0,j].bInR := true;
          data[0,j].InR := color;
        end;
    end else
    begin
      j := (number - 1) div 2 + 1;
      if (number mod 2 = 0) then
        begin
          data[0,j].bInR := true;
          data[0,j].InR := color;
        end else
        begin
          data[0,j].bInL := true;
          data[0,j].InL := color;
        end;
    end;
   for i := 0 to N do
    for j := 0 to M do
      UpdateKnot(data, i,j);
end;

function TScheme.GetStreamNumber(x: Integer; y: Integer; p: Byte) : integer;
begin
  if x = 0 then
    begin
      if (SchemeType = 1)OR(SchemeType = 3) then
        begin
          if p = 3 then result := 2*y else
          if p = 4 then result := 2*y + 1;
        end else
        begin
          if p = 3 then result := 2*y - 1 else
          if p = 4 then result := 2*y;
        end;
      exit;
    end;
  case p of
    1: begin
        if (x mod 2 = 0) then
          result := GetStreamNumber(x - 1, y - 1, 4) else
          result := GetStreamNumber(x - 1, y, 4);
       end;
    2: begin
        if (x mod 2 = 0) then
          result := GetStreamNumber(x - 1, y, 3) else
          result := GetStreamNumber(x - 1, y + 1, 3);
       end;
    3: begin
        case data[x,y].value of
         NA: result := -1;
         LL, RR, AL: result := GetStreamNumber(x, y, 1);
         LR, RL: result := GetStreamNumber(x, y, 2);
        end;
       end;
    4: begin
        case data[x,y].value of
         NA: result := -1;
         LL, RR, AR: result := GetStreamNumber(x, y, 2);
         LR, RL: result := GetStreamNumber(x, y, 1);
        end;
       end;
  end;
end;

procedure TScheme.UpdatePreview;
var
  i, j, k : integer;
begin
  SetLength(datapv, Npv + 1);
  for i := 0 to Npv do
    SetLength(datapv[i], M + 1);
  for j := 0 to M do
    begin
      datapv[0,j] := data[0,j];
      UpdateKnot(datapv, 0, j);
    end;
  for i := 1 to Npv do
  begin
    k := (i-1)mod(N-1)+1;
    for j := 0 to M do
      begin
        datapv[i,j] := data[k,j];
        UpdateKnot(datapv, i, j);
      end;
  end;
end;

procedure TScheme.ChangePreview(d: Integer);
begin
  if (Rpv+d > 1)AND(Rpv+d < 11) then SetPreview(Rpv+d);
end;

procedure TScheme.SetPreview(newR: Integer);
begin
  Rpv := newR;
end;

procedure TScheme.GetDimensions(var xsc: Integer; var ysc: Integer;
                                var xpv: Integer; var ypv: Integer);
begin
  xsc := (M+1)*10*R + 2*R;
  ysc := (N+1)*5*R + dy;
  xpv := M*2*Rpv + Rpv + 1;
  ypv := (Npv+3)*Rpv;
end;

procedure TScheme.SetPreviewLines(Nlines: Integer);
begin
  if (Npv <> Nlines)AND(Nlines >= 2) then
    begin
      Npv := Nlines;
      UpdatePreview;
    end;
end;

procedure TScheme.AddLines;
var
  i, j : integer;
  buf : TSchemeData;
begin
  SetLength(buf, N+3);
  for i := 0 to N+2 do
    SetLength(buf[i],M+1);
  for i := 0 to N-1 do
    for j := 0 to M do
      buf[i,j] := data[i,j];
  for i := 1 to 2 do
    for j := 0 to M do
      begin
        if (data[i,j].value = LR)OR(data[i,j].value = RL)OR
           (data[i,j].value = LL)OR(data[i,j].value = RR) then
          buf[N-1+i,j].value := NA else
          buf[N-1+i,j].value := data[i,j].value;
        UpdateKnot(buf, N-1+i, j);
      end;
  for j := 0 to M do
    begin
     buf[N+2,j] := data[N,j];
     UpdateKnot(buf, N+2, j);
    end;
  N := N + 2;
  data := buf;
end;

procedure TScheme.DelLines;
var
  i, j : integer;
  buf : TSchemeData;
begin
  if N <= 3 then exit;
  SetLength(buf, N-1);
  for i := 0 to N-2 do
    SetLength(buf[i],M+1);
  for i := 0 to N-3 do
    for j := 0 to M do
      buf[i,j] := data[i,j];
  for j := 0 to M do
    begin
      buf[N-2,j] := data[N,j];
      UpdateKnot(buf, N-2, j);
    end;
  N := N - 2;
  data := buf;
end;

function TScheme.SaveToFile(fname: string) : boolean;
var
  f : file;
  i, j : integer;
  SetColorTab : array of boolean;
begin
  result := true;
  try
    Assign(f, fname);
    Rewrite(f, 1);
    BlockWrite(f, N, SizeOf(N));
    BlockWrite(f, M, SizeOf(M));
    BlockWrite(f, SchemeType, SizeOf(SchemeType));
    for i := 0 to N do
      for j := 0 to M do
        BlockWrite(f, data[i,j].value, SizeOf(data[i,j].value));
     SetLength(SetColorTab, (M + 1)*2);
     for j := 0 to M do
       begin
         if data[0,j].bInL then
          SetColorTab[2*j] := true else
          SetColorTab[2*j] := false;
         if data[0,j].bInR then
          SetColorTab[2*j+1] := true else
          SetColorTab[2*j+1] := false;
       end;
    for i := 0 to (2*M + 1) do
      BlockWrite(f, SetColorTab[i], SizeOf(SetColorTab[i]));
    for j := 0 to M do
     begin
      if data[0,j].bInL then
        BlockWrite(f, data[0,j].InL, SizeOf(data[0,j].InL));
      if data[0,j].bInR then
        BlockWrite(f, data[0,j].InR, SizeOf(data[0,j].InR));
      end;
    BlockWrite(f, NColorGroups, SizeOf(NColorGroups));
    for i := 0 to NColorGroups - 1 do
      BlockWrite(f, ColorGroups[i], SizeOf(ColorGroups[i]));
    for i := 0 to Nths - 1 do
      BlockWrite(f, ThColorGr[i], SizeOf(ThColorGr[i]));
    Close(f);
  except
    result := false;
  end;
end;

function TScheme.LoadFromFile(fname: string) : boolean;
var
  f : file;
  i, j : integer;
  SetColorTab : array of boolean;
begin
  result := true;
  try
    Assign(f, fname);
    System.Reset(f, 1);
    BlockRead(f, N, SizeOf(N));
    BlockRead(f, M, SizeOf(M));
    BlockRead(f, SchemeType, SizeOf(SchemeType));
    SetLength(data, N + 1);
    for i := 0 to N do
     SetLength(data[i], M + 1);
    for i := 0 to N do
      for j := 0 to M do
        BlockRead(f, data[i,j].value, SizeOf(data[i,j].value));
    SetLength(SetColorTab, (M + 1)*2);
    for i := 0 to (2*M + 1) do
     BlockRead(f, SetColorTab[i], SizeOf(SetColorTab[i]));
    for j := 0 to M do
      begin
       if SetColorTab[j*2] then
        begin
          data[0,j].bInL := true;
          BlockRead(f, data[0,j].InL, SizeOf(data[0,j].InL));
        end else
          data[0,j].bInL := false;
       if SetColorTab[j*2+1] then
        begin
          data[0,j].bInR := true;
          BlockRead(f, data[0,j].InR, SizeOf(data[0,j].InR));
        end else
          data[0,j].bInR := false;
      end;
  for i := 0 to N do
   for j := 0 to M do
      UpdateKnot(data, i, j);
  case SchemeType of
  1, 4: Nths := M*2;
  2: Nths := M*2 - 1;
  3: Nths := M*2 + 1;
  end;
  ResetColorGroups;
  if NOT EOF(f) then
  begin
    BlockRead(f, NColorGroups, SizeOf(NColorGroups));
    SetLength(ColorGroups, NColorGroups);
    for i := 0 to NColorGroups - 1 do
      BlockRead(f, ColorGroups[i], SizeOf(ColorGroups[i]));
    for i := 0 to Nths - 1 do
      BlockRead(f, ThColorGr[i], SizeOf(ThColorGr[i]));
  end;
  except
    result := false;
  end;
  Close(f);
end;

function TScheme.LoadFromRNXFile(fname: string) : boolean;
var
  f : file;
  i, j, Nthreads, Ndblrows, dblrwcount, j1, j2 : integer;
  color : TColor;
  dblrow : TDoubleRow;
begin
  result := true;
  try
    Assign(f, fname);
    System.Reset(f, 1);
    BlockRead(f, Nthreads, 4);
    Nths := Nthreads;
    BlockRead(f, Ndblrows, 4);
    Reset(2, Nthreads, false);
    j1 := Nthreads div 2 - 1;
    j2 := Nthreads div 2 + Nthreads mod 2 - 1;
    SetLength(dblrow[1], j1 + 1);
    SetLength(dblrow[2], j2 + 1);
    for i := 1 to Nthreads do
      begin
        BlockRead(f, color, 4);
        if (i mod 2 = 1) then
          begin
            data[0,(i div 2)].bInR := true;
            data[0,(i div 2)].InR := color;
          end else
          begin
            data[0,(i div 2)].bInL := true;
            data[0,(i div 2)].InL := color;
          end;
      end;
      for j := 0 to j1 do
        BlockRead(f, dblrow[1,j], 1);
      for j := 1 to j2 do
        BlockRead(f, dblrow[2,j], 1);
    dblrwcount := 0;
    while (dblrwcount < Ndblrows)AND(CheckRNXDoubleRow(dblrow, j1, j2)) do
    begin
       if dblrwcount > 0 then AddLines;
       for j := 0 to j1 do
         data[1+dblrwcount*2,j].value := ConvertRNXKnot(dblrow[1,j]);
       for j := 1 to j2 do
         data[2+dblrwcount*2,j].value := ConvertRNXKnot(dblrow[2,j]);
       dblrwcount := dblrwcount + 1;
       if dblrwcount < Ndblrows then
        begin
          for j := 0 to j1 do
            BlockRead(f, dblrow[1,j], 1);
          for j := 1 to j2 do
            BlockRead(f, dblrow[2,j], 1);
        end;
    end;
    Optimize;
    for i := 0 to N do
      for j := 0 to M do
         UpdateKnot(data, i, j);
  except
    result := false;
  end;
  Close(f);
  ResetColorGroups;
end;

function TScheme.ConvertRNXKnot(k: Byte) : byte;
begin
  case k of
  0, 1 : result := LL;
  2, 6 : result := LR;
  3, 7 : result := RL;
  4 :    result := LL;
  5 :    result := RR;
  end;
end;

function TScheme.CheckRNXDoubleRow(dblrow: TDoubleRow;
                                   j1: Integer; j2: Integer) : boolean;
var
  j : integer;
begin
  result := false;
  for j := 0 to j1 do
    if dblrow[1,j] > 1 then
      result := true;
  for j := 1 to j2 do
    if dblrow[2,j] > 1 then
      result := true;
end;

function TScheme.GetStreamColor(number : integer; var color: TColor) : boolean;
var
  j : integer;
begin
  result := false;
  if (SchemeType = 1)OR(SchemeType = 3) then
    begin
      j := number div 2;
      if (number mod 2 = 0) then
        begin
          if data[0,j].bInL then
            begin
              color := data[0,j].InL;
              result := true;
            end;
        end else
        begin
         if data[0,j].bInR then
           begin
             color := data[0,j].InR;
             result := true;
           end;
        end;
    end else
    begin
      j := (number - 1) div 2 + 1;
      if (number mod 2 = 0) then
        begin
          if data[0,j].bInR then
            begin
             color := data[0,j].InR;
             result := true;
            end;
        end else
        begin
          if data[0,j].bInL then
           begin
            color := data[0,j].InL;
            result := true;
           end;
        end;
    end;
end;

function TScheme.Optimize : boolean;
var
  i, NS : integer;
begin
  i := 2;
  NS := N;
  while (i <= (NS-1) div 2)AND(NOT OptimizeAt(i)) do
    i := i + 2;
  if i > (NS-1) div 2 then result := false else
                           result := true;
end;

function TScheme.OptimizeAt(OptN: Integer) : boolean;
var
  i, j, k, Ndupl : integer;
  R : boolean;
begin
  if ((N-1) mod OptN) <> 0 then
    begin
      result := false;
      exit;
    end;
  Ndupl := (N-1) div OptN;
  R := true;
  k := 1;
  while (R)AND(k < Ndupl) do
    begin
     i := 1;
      while (R)AND(i <= OptN) do
        begin
          j := 0;
          while (R)AND(j <= M) do
            begin
              if data[i+OptN*k,j].value <> data[i,j].value then
                R := false;
              j := j + 1;
            end;
          i := i + 1;
        end;
      k := k + 1;
    end;
  if R then
    begin
      k := (OptN*(Ndupl - 1)) div 2;
      for i := 1 to k do
        DelLines;
    end;
  result := R;
end;

procedure TScheme.AddRThread;
var
  i, j : integer;
  buf : TSchemeData;
  buf2 : TThColorGr;
begin
  if (SchemeType = 1)OR(SchemeType = 2) then
    begin
      data[0,M].value := SRL;
      data[0,M].bInR := false;
      data[N,M].value := FL;
      for i := 1 to N-1 do
        begin
          if (i mod 2 = 0) then
            data[i,M].value := NA else
            data[i,M].value := AL;
        end;
      SchemeType := SchemeType + 2;
    end else
    begin
      SetLength(buf, N+1);
      for i := 0 to N do
        SetLength(buf[i],M+2);
      M := M + 1;
      for i := 0 to N do
        for j := 0 to M-1 do
          buf[i,j] := data[i,j];
      buf[0,M].value := SL;
      buf[0,M].bInL := false;
      buf[N,M-1].value := FRL;
      buf[N,M].value := ZR;
      for i := 1 to N-1 do
        begin
          if (i mod 2 = 0) then
            buf[i,M].value := AL else
            begin
              buf[i,M].value := ZR;
              buf[i,M-1].value := NA;
            end;
        end;
      SchemeType := SchemeType - 2;
      data := buf;
    end;
  Nths := Nths + 1;
  for i := 0 to N do
    for j := 0 to M do
      UpdateKnot(data, i, j);
  SetLength(buf2, Nths);
  for i := 0 to Nths - 2 do
    buf2[i] := ThColorGr[i];
  buf2[Nths-1] := -1;
  ThColorGr := buf2;
end;

procedure TScheme.DelRThread;
var
  i, j : integer;
  buf : TSchemeData;
  buf2 : TThColorGr;
begin
  if Nths < 3 then  exit;
  if (SchemeType = 1)OR(SchemeType = 2) then
    begin
      SetLength(buf, N+1);
      M := M - 1;
      for i := 0 to N do
        SetLength(buf[i], M+1);
      for i := 0 to N do
        for j := 0 to M do
          buf[i,j] := data[i,j];
      buf[N,M].value := FL;
      for i := 1 to N-1 do
        if (i mod 2 = 1) then
          buf[i,M].value := AL;
      SchemeType := SchemeType + 2;
      data := buf;
    end else
    begin
      data[0,M].value := SL;
      for i := 1 to N do
        begin
          if (i mod 2 = 1) then
             data[i,M].value := ZR else
             data[i,M].value := AL;
        end;
      SchemeType := SchemeType - 2;
    end;
  Nths := Nths - 1;
  for i := 0 to N do
    for j := 0 to M do
      UpdateKnot(data, i, j);
  SetLength(buf2, Nths);
  for i := 0 to Nths - 1 do
    buf2[i] := ThColorGr[i];
  ThColorGr := buf2;
end;

procedure TScheme.AddLThread;
var
  i, j : integer;
  buf : TSchemeData;
  buf2 : TThColorGr;
begin
  if (SchemeType = 2)OR(SchemeType = 4) then
    begin
      data[0,0].value := SR;
      data[0,0].bInR := false;
      data[N,0].value := FRL;
      for i := 1 to N-1 do
        begin
          if (i mod 2 = 1) then
            data[i,0].value := NA else
            data[i,0].value := AR;
        end;
      SchemeType := SchemeType - 1;
    end else
    begin
      SetLength(buf, N+1);
      for i := 0 to N do
        SetLength(buf[i], M+2);
      for i := 0 to N do
        for j := 0 to M do
          buf[i,j+1] := data[i,j];
      buf[0,0].value := ZR;
      buf[0,1].value := SRL;
      buf[0,1].bInL := false;
      buf[N,0].value := FR;
      for i := 1 to N-1 do
        begin
          if (i mod 2 = 0) then
            begin
              buf[i,0].value := ZR;
              buf[i,1].value := NA;
            end else
              buf[i,0].value := AR;
        end;
      M := M+1;
      data := buf;
      SchemeType := SchemeType + 1;
    end;
  Nths := Nths + 1;
  for i := 0 to N do
    for j := 0 to M do
      UpdateKnot(data, i, j);
  SetLength(buf2, Nths);
  for i := 1 to Nths - 1 do
    buf2[i] := ThColorGr[i-1];
  buf2[0] := -1;
  ThColorGr := buf2;
end;

procedure TScheme.DelLThread;
var
  i, j : integer;
  buf : TSchemeData;
  buf2 : TThColorGr;
begin
  if Nths < 3 then  exit;
  if (SchemeType = 1)OR(SchemeType = 3) then
    begin
      data[N,0].value := FR;
      for i := 0 to N - 1 do
        begin
          if (i mod 2 = 0) then
            data[i,0].value := ZR else
            data[i,0].value := AR;
        end;
      SchemeType := SchemeType + 1;
    end else
    begin
      M := M - 1;
      SetLength(buf, N+1);
      for i := 0 to N do
        SetLength(buf[i], M+1);
      for i := 0 to N do
        for j := 0 to M do
          buf[i,j] := data[i, j+1];
      buf[0,0].value := SR;
      for i := 1 to N - 1 do
        if (i mod 2 = 0) then
          buf[i,0].value := AR;
      data := buf;
      SchemeType := SchemeType - 1;
    end;
  Nths := Nths - 1;
  for i := 0 to N do
    for j := 0 to M do
      UpdateKnot(data, i, j);
    SetLength(buf2, Nths);
  for i := 0 to Nths - 1 do
    buf2[i] := ThColorGr[i+1];
  ThColorGr := buf2;
end;

procedure TScheme.ResetColorGroups;
var i : integer;
begin
  NColorGroups := 0;
  SetLength(ThColorGr, Nths);
  for i := 0 to Nths - 1 do
    ThColorGr[i] := -1;
 ColorGroups := nil;
end;

procedure TScheme.AddThreadToGroup(th: Integer; gr: Integer);
var
  c : TColor;
  i, j : integer;
begin
  ThColorGr[th-1] := gr;
  if (ColorGroups[gr].empty) then
    begin
      if (GetStreamColor(th, c)) then
        begin
          ColorGroups[gr].empty := false;
          ColorGroups[gr].color := c;
          for i := 0 to N do
            for j := 0 to M do
              UpdateKnot(data, i, j);
        end;
    end else
    SetStreamColor(ColorGroups[gr].color, th);
end;

procedure TScheme.DelThreadFromGroup(th: integer);
begin
  ThColorGr[th-1] := -1;
end;

procedure TScheme.AddColorGroup;
var
  i : integer;
  buf : TColorGroups;
begin
  if (NColorGroups > 0)AND(ColorGroups[NColorGroups-1].empty) then exit;
  
  NColorGroups := NColorGroups + 1;
  SetLength(buf, NColorGroups);
  for i := 0 to NColorGroups - 2 do
    buf[i] := ColorGroups[i];
  buf[NColorGroups-1].empty := true;
  ColorGroups := buf;
end;

procedure TScheme.DelColorGroup(gr: Integer);
var
  i : integer;
  buf : TColorGroups;
begin
  if NColorGroups < 1 then exit;
  NColorGroups := NColorGroups - 1;
  SetLength(buf, NColorGroups);
  for i := 0 to gr - 1 do
    buf[i] := ColorGroups[i];
  for i := gr to NColorGroups - 1 do
    buf[i] := ColorGroups[i+1];
  ColorGroups := buf;
  ChangeThreadsGroup(gr, -1);
  for i := gr to NColorGroups do
    ChangeThreadsGroup(i, i - 1);
end;

procedure TScheme.ChangeThreadsGroup(v0: Integer; v: Integer);
var
  i : integer;
begin
  for i := 1 to Nths do
    if ThColorGr[i-1] = v0 then
      ThColorGr[i-1] := v;
end;

procedure TScheme.SetStreamColorWithGroup(color: TColor; number: Integer);
var
  i : integer;
begin
  if ThColorGr[number-1] = -1 then
    begin
      SetStreamColor(color, number);
      exit;
    end;
  ColorGroups[ThColorGr[number-1]].color := color;
  ColorGroups[ThColorGr[number-1]].empty := false;
  for i := 1 to Nths do
    if ThColorGr[i-1] = ThColorGr[number-1] then
      SetStreamColor(color, i);
end;

procedure TScheme.GroupByColors;
var
  i, j : integer;
  c1, c2 : TColor;
  first : boolean;
begin
  ResetColorGroups;
  for i := 1 to Nths - 1 do
    begin
      if ThColorGr[i-1] = -1 then
        begin
          GetStreamColor(i, c1);
          first := true;
          for j := i to Nths do
            begin
              GetStreamColor(j, c2);
              if c2 = c1 then
                begin
                  if first then
                    begin
                      first := false;
                      AddColorGroup;
                      AddThreadToGroup(i, NColorGroups - 1);
                    end;
                   ThColorGr[j-1] := ThColorGr[i-1];
                end;
            end;
        end;
    end;
end;

end.
