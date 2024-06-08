; �������������������������������������������������������������������������

      .686p                     ; create 32 bit code
      .MMX                      ; enable MMX instructions
      .XMM                      ; enable SSE instructions
      .model flat, stdcall      ; 32 bit memory model
      option casemap :none      ; case sensitive

      include Project.inc        ; local includes for this file
      include \masm32\include\dialogs.inc


.code

start:

; �������������������������������������������������������������������������

    ; ------------------
    ; set global values
    ; ------------------
      mov hInstance,   rv(GetModuleHandle, NULL)
      mov CommandLine, rv(GetCommandLine)
      mov hIcon,       rv(LoadIcon,hInstance,500)
      mov hCursor,     rv(LoadCursor,NULL,IDC_ARROW)
      mov sWid,        rv(GetSystemMetrics,SM_CXSCREEN)
      mov sHgt,        rv(GetSystemMetrics,SM_CYSCREEN)

      call Main

      dlgproc PROTO :DWORD,:DWORD,:DWORD,:DWORD

      invoke ExitProcess,eax

; �������������������������������������������������������������������������

Main proc

    LOCAL Wwd:DWORD,Wht:DWORD,Wtx:DWORD,Wty:DWORD,mWid:DWORD
    LOCAL icce      :INITCOMMONCONTROLSEX

    mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX

  ; ------------------------------------------------------------------
  ; Add different cotrols by adding different styles to the icce.dwICC
  ; member of the INITCOMMONCONTROLSEX structure. Reference for the
  ; styles can be found in the INITCOMMONCONTROLSEX help information
  ; ------------------------------------------------------------------
    mov icce.dwICC,  ICC_COOL_CLASSES or ICC_BAR_CLASSES
    invoke InitCommonControlsEx,ADDR icce

    STRING szClassName,"ProStart_Class"

  ; --------------------------------------------
  ; register class name for CreateWindowEx call
  ; --------------------------------------------
    invoke RegisterWinClass,ADDR WndProc,ADDR szClassName,
                       hIcon,hCursor,COLOR_BTNFACE+1

  ; ---------------------------------------------
  ; set width and height as percentages of screen
  ; ---------------------------------------------
    invoke GetPercent,sWid,75
    mov Wwd, eax
    invoke GetPercent,sHgt,70
    mov Wht, eax

  ; ----------------------
  ; set aspect ratio limit
  ; ----------------------
    FLOAT4 aspect_ratio, 1.4    ; set the maximum startup aspect ratio

    fild Wht                    ; load source
    fld aspect_ratio            ; load multiplier
    fmul                        ; multiply source by multiplier
    fistp mWid                  ; store result in variable

    mov eax, Wwd
    .if eax > mWid              ; if the default window width is > aspect ratio
      m2m Wwd, mWid             ; set the width to the maximum aspect ratio
    .endif

  ; ------------------------------------------------
  ; Top X and Y co-ordinates for the centered window
  ; ------------------------------------------------
    mov eax, sWid
    sub eax, Wwd                ; sub window width from screen width
    shr eax, 1                  ; divide it by 2
    mov Wtx, eax                ; copy it to variable

    mov eax, sHgt
    sub eax, Wht                ; sub window height from screen height
    shr eax, 1                  ; divide it by 2
    mov Wty, eax                ; copy it to variable

    invoke CreateWindowEx,WS_EX_LEFT or WS_EX_ACCEPTFILES,
                          ADDR szClassName,
                          ADDR szDisplayName,
                          WS_OVERLAPPEDWINDOW,
                          Wtx,Wty,Wwd,Wht,
                          NULL,NULL,
                          hInstance,NULL
    mov hWnd,eax

  ; ---------------------------
  ; macros for unchanging code
  ; ---------------------------
    DisplayMenu hWnd,600
    DisplayWindow hWnd,SW_SHOWNORMAL

    call MsgLoop
    ret

Main endp

; �������������������������������������������������������������������������

RegisterWinClass proc lpWndProc:DWORD, lpClassName:DWORD,
                      Icon:DWORD, Cursor:DWORD, bColor:DWORD

    LOCAL wc:WNDCLASSEX

    mov wc.cbSize,         sizeof WNDCLASSEX
    mov wc.style,          CS_BYTEALIGNCLIENT or \
                           CS_BYTEALIGNWINDOW
    m2m wc.lpfnWndProc,    lpWndProc
    mov wc.cbClsExtra,     NULL
    mov wc.cbWndExtra,     NULL
    m2m wc.hInstance,      hInstance
    m2m wc.hbrBackground,  bColor
    mov wc.lpszMenuName,   NULL
    m2m wc.lpszClassName,  lpClassName
    m2m wc.hIcon,          Icon
    m2m wc.hCursor,        Cursor
    m2m wc.hIconSm,        Icon

    invoke RegisterClassEx, ADDR wc

    ret

RegisterWinClass endp

; �������������������������������������������������������������������������

MsgLoop proc

    LOCAL msg:MSG

    push esi
    push edi
    xor edi, edi                        ; clear EDI
    lea esi, msg                        ; Structure address in ESI
    jmp jumpin

    StartLoop:
      invoke TranslateMessage, esi
    ; ----------------------------------------
    ; perform any required key processing here
    ; ----------------------------------------
      invoke DispatchMessage,  esi
    jumpin:
      invoke GetMessage,esi,edi,edi,edi
      test eax, eax
      jnz StartLoop

    mov eax, msg.wParam
    pop edi
    pop esi

    ret

MsgLoop endp

; �������������������������������������������������������������������������

proc1 proc
LOCAL icce:INITCOMMONCONTROLSEX
mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX
mov icce.dwICC, ICC_DATE_CLASSES
invoke InitCommonControlsEx,ADDR icce
Dialog "Tekst","MS Sans Serif",11, \ ; caption,font,pointsize
WS_OVERLAPPED or DS_CENTER, \ ; style
2, \ ; control count
50,50,189,125, \ ; x y co-ordinates
1024 ; memory buffer size

; TODO
DlgStatic "Politechnika Slaska", WS_CHILD or WS_VISIBLE or SS_CENTER, 10, 10, 169, 20, 1000

DlgButton "Close", WS_TABSTOP, 10, 80, 40, 12, IDCANCEL

CallModalDialog hInstance,0,dlgproc,NULL
ret
proc1 endp

proc2 proc
LOCAL icce:INITCOMMONCONTROLSEX
mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX
mov icce.dwICC, ICC_DATE_CLASSES
invoke InitCommonControlsEx,ADDR icce

Dialog "Kwestionariusz","MS Sans Serif",11, \ ; caption,font,pointsize
WS_OVERLAPPED or DS_CENTER, \ ; style
6, \ ; control count
50,50,189,160, \ ; x y co-ordinates
1024 ; memory buffer size

; TODO
DlgStatic "W ktorym roku powstal MASM?", WS_CHILD or WS_VISIBLE or SS_CENTER, 10, 10, 169, 20, 1000
DlgCheck "1980", WS_CHILD or WS_VISIBLE or BS_AUTOCHECKBOX, 10, 30, 169, 20, 1001
DlgCheck "1981", WS_CHILD or WS_VISIBLE or BS_AUTOCHECKBOX, 10, 50, 169, 20, 1002
DlgCheck "1982", WS_CHILD or WS_VISIBLE or BS_AUTOCHECKBOX, 10, 70, 169, 20, 1003
DlgCheck "1983", WS_CHILD or WS_VISIBLE or BS_AUTOCHECKBOX, 10, 90, 169, 20, 1004

DlgButton "Close", WS_TABSTOP, 10, 120, 40, 12, IDCANCEL

CallModalDialog hInstance,0,dlgproc,NULL
ret
proc2 endp

proc3 proc
LOCAL icce:INITCOMMONCONTROLSEX
mov icce.dwSize, SIZEOF INITCOMMONCONTROLSEX
mov icce.dwICC, ICC_DATE_CLASSES
invoke InitCommonControlsEx,ADDR icce

Dialog "Pole tekstowe","MS Sans Serif",11, \ ; caption,font,pointsize
WS_OVERLAPPED or DS_CENTER, \ ; style
3, \ ; control count
50,50,189,125, \ ; x y co-ordinates
1024 ; memory buffer size

; Add a static text label
DlgStatic "Wprowadz tekst:", WS_CHILD or WS_VISIBLE, 10, 10, 169, 20, 1000

; Add the text field
DlgEdit WS_BORDER or ES_LEFT, 10, 40, 169, 20, 1001

; Add the close button
DlgButton "Close", WS_TABSTOP, 10, 80, 40, 12, IDCANCEL

CallModalDialog hInstance,0,dlgproc,NULL
ret
proc3 endp

dlgproc proc hWin: DWORD, uMsg: DWORD, wParam: DWORD, lParam: DWORD
  .if uMsg == WM_INITDIALOG
    invoke SendMessage, hWin,WM_SETICON, 1, FUNC(LoadIcon, NULL, IDI_ASTERISK)
  .elseif uMsg == WM_COMMAND
    .if wParam == IDCANCEL
      jmp quit_dialog
    .endif
  .elseif uMsg == WM_CLOSE
  quit_dialog:
    invoke EndDialog, hWin, 0
  .endif
xor eax, eax
ret
dlgproc endp

; �������������������������������������������������������������������������

WndProc proc hWin:DWORD,uMsg:DWORD,wParam:DWORD,lParam:DWORD

    LOCAL var    :DWORD
    LOCAL caW    :DWORD
    LOCAL caH    :DWORD
    LOCAL fname  :DWORD
    LOCAL patn   :DWORD
    LOCAL Rct    :RECT
    LOCAL buffer1[260]:BYTE  ; these are two spare buffers
    LOCAL buffer2[260]:BYTE  ; for text manipulation etc..

    Switch uMsg
      Case WM_COMMAND

        Switch wParam
        ;======== toolbar commands ========
          Case 50
            fn MessageBox,hWin,"Laboratorium Jezykow Asemblerowych",ADDR szDisplayName,MB_OK
          Case 51
            call proc1
          Case 52
            call proc2
          Case 53
            call proc3
          Case 54
            fn MessageBox,hWin,"Lorem ipsum dolor sit amet",ADDR szDisplayName,MB_OK

        ;======== menu commands ========

          Case 1001
            sas patn, "All files",0,"*.*",0
            mov fname, OpenFileDlg(hWin,hInstance,"Open File",patn)
            cmp BYTE PTR [eax], 0
            jne @F
            return 0
            @@:
          ; ---------------------------------
          ; perform your file open code here
          ; ---------------------------------
            invoke MessageBox,hWin,fname,ADDR szDisplayName,MB_OK

          Case 1002
            sas patn, "All files",0,"*.*",0
            mov fname, SaveFileDlg(hWin,hInstance,"Save File As ...",patn)
            cmp BYTE PTR [eax], 0
            jne @F
            return 0
            @@:
          ; ---------------------------------
          ; perform your file save code here
          ; ---------------------------------
            invoke MessageBox,hWin,fname,ADDR szDisplayName,MB_OK

          Case 1010
            invoke SendMessage,hWin,WM_SYSCOMMAND,SC_CLOSE,NULL

          Case 1900
            ShellAboutBox hWin,hIcon,\
              "About Prostart 5 Template#Windows Application",\
              "Prostart 5 Template",13,10,"Copyright � MASM32 1998-2011"

          ;====== end menu commands ======
      Endsw

      Case WM_DROPFILES
        mov fname, DropFileName(wParam)
        fn MessageBox,hWin,fname,"WM_DROPFILES",MB_OK

      Case WM_CREATE
        invoke Do_ToolBar,hWin
        invoke Do_Status,hWin

      Case WM_SYSCOLORCHANGE
        invoke Do_ToolBar,hWin

      Case WM_SIZE
        invoke SendMessage,hToolBar,TB_AUTOSIZE,0,0
        invoke MoveWindow,hStatus,0,0,0,0,TRUE

      Case WM_PAINT
        invoke Paint_Proc,hWin
        return 0

      Case WM_CLOSE

      Case WM_DESTROY
        invoke PostQuitMessage,NULL
        return 0

    Endsw

    invoke DefWindowProc,hWin,uMsg,wParam,lParam

    ret

WndProc endp

; �������������������������������������������������������������������������

Paint_Proc proc hWin:DWORD

    LOCAL hDC      :DWORD
    LOCAL btn_hi   :DWORD
    LOCAL btn_lo   :DWORD
    LOCAL Rct      :RECT
    LOCAL Ps       :PAINTSTRUCT

    mov hDC, rv(BeginPaint,hWin,ADDR Ps)

  ; ----------------------------------------

    mov btn_hi, rv(GetSysColor,COLOR_BTNHIGHLIGHT)

    mov btn_lo, rv(GetSysColor,COLOR_BTNSHADOW)

  ; ----------------------------------------

    invoke EndPaint,hWin,ADDR Ps

    ret

Paint_Proc endp

; �������������������������������������������������������������������������

end start
