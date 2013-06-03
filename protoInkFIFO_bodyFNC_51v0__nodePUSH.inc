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
    {$if defined (_M_protoInkFIFO_51v0__var_STACK)}
        {$define _var_piFifo51v0_STACK:=_M_protoInkFIFO_51v0__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_51v0__cst_NODE)}
        {$define _cst_piFifo51v0_NODE:=_M_protoInkFIFO_51v0__cst_NODE}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_51v0__lcl_getNext)}
        {$define _prc_piFifo51v0_getNext:=_M_protoInkFIFO_51v0__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _prc_piFifo51v0_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_51v0__lcl_setNext)}
        {$define _prc_piFifo51v0_setNext:=_M_protoInkFIFO_51v0__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifo51v0_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_16__insNodeSecond'}{$endIF}
    {$deFine _M_protoInkLLc_16__var_FIRST  :=_var_piFifo51v0_STACK}
    {$deFine _M_protoInkLLc_16__cst_NODE   :=_cst_piFifo51v0_NODE}
    {$deFine _M_protoInkLLc_16__lcl_getNext:=_prc_piFifo51v0_getNext}
    {$deFine _M_protoInkLLc_16__lcl_setNext:=_prc_piFifo51v0_setNext}
    {$I protoInkLLc_bodyFNC_16__insNodeSecond.inc}
    //---
    {$ifDef inkFIFO_fncHeadMessage}{$message '<<main code>>'}{$endIF}
   _var_piFifo51v0_STACK:=_cst_piFifo51v0_NODE;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Local macros
    {$unDef _var_piFifo51v0_STACK}
    {$unDef _cst_piFifo51v0_NODE}
    {$unDef _prc_piFifo51v0_getNext}
    {$unDef _prc_piFifo51v0_setNext}
    //--- undef user
    {$unDef _M_protoInkFIFO_51v0__var_STACK}
    {$unDef _M_protoInkFIFO_51v0__cst_NODE}
    {$unDef _M_protoInkFIFO_51v0__lcl_getNext}
    {$unDef _M_protoInkFIFO_51v0__lcl_setNext}
{%endregion 'unDEF used macros' /fold}
