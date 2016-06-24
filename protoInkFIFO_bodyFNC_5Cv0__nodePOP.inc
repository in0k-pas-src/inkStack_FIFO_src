{//-----------------------------------------------[ mangust © 29.01.2010 ]---///
///                                 _____ _ ___                              ///
///            +-+-+-+-+-+_     _  |   __|_|  _|___last -> -                 ///
///            |  PRoTo  |_|___| |_|   __| |  _| . | first -                 ///
///            +-+-+-+-+-| |   | '_|__|  |_|_| |___|       -                 ///
///                      |_|_|_|_,_|    v 4.0      last <- =                 ///
///                                                                          ///
///--------------------------------------------[ v 4.0 in0k © 29.05.2013 ]---//}
{%region /fold 'check "define" for all used macros'                      }
    //--- VARs
    {$if defined (_M_protoInkFIFO_5Cv0__var_STACK)}
        {$define _var_piFifo5Cv0_STACK:=_M_protoInkFIFO_5Cv0__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv0__out_NODE)}
        {$define _out_piFifo5Cv0_NODE:=_M_protoInkFIFO_5Cv0__out_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_5Cv0__lcl_getNext)}
        {$define _fnc_piFifo5Cv0_getNext:=_M_protoInkFIFO_5Cv0__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo5Cv0_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_5Cv0__lcl_setNext)}
        {$define _fnc_piFifo5Cv0_setNext:=_M_protoInkFIFO_5Cv0__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _fnc_piFifo5Cv0_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
   _out_piFifo5Cv0_NODE:=_var_piFifo5Cv0_STACK;
    if _out_piFifo5Cv0_NODE<>nil then begin
        if _fnc_piFifo5Cv0_getNext(_out_piFifo5Cv0_NODE)<>_out_piFifo5Cv0_NODE then begin
            {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_C2__cutNodeSecond'}{$endIF}
            {$deFine _M_protoInkLLc_C2__cst_FIRST  :=_var_piFifo5Cv0_STACK}
            {$deFine _M_protoInkLLc_C2__out_NODE   :=_out_piFifo5Cv0_NODE}
            {$deFine _M_protoInkLLc_C2__lcl_getNext:=_fnc_piFifo5Cv0_getNext}
            {$deFine _M_protoInkLLc_C2__lcl_setNext:=_fnc_piFifo5Cv0_setNext}
            {$I protoInkLLc_bodyFNC_C2__cutNodeSecond.inc}
        end
        else begin
           _var_piFifo5Cv0_STACK:=NIL;
        end;
    end;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _var_piFifo5Cv0_STACK}
    {$unDef _out_piFifo5Cv0_NODE}
    {$unDef _fnc_piFifo5Cv0_getNext}
    {$unDef _fnc_piFifo5Cv0_setNext}
    //--- undef user
    {$unDef _M_protoInkFIFO_5Cv0__var_STACK}
    {$unDef _M_protoInkFIFO_5Cv0__out_NODE}
    {$unDef _M_protoInkFIFO_5Cv0__lcl_getNext}
    {$unDef _M_protoInkFIFO_5Cv0__lcl_setNext}
{%endregion 'unDEF used macros' /fold}
