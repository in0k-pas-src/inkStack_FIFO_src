{//-----------------------------------------------[ mangust © 29.01.2010 ]---///
///                                 _____ _ ___                              ///
///            +-+-+-+-+-+_     _  |   __|_|  _|___last -> -                 ///
///            |  PRoTo  |_|___| |_|   __| |  _| . | first -                 ///
///            +-+-+-+-+-| |   | '_|__|  |_|_| |___|       -                 ///
///                      |_|_|_|_,_|    v 4.0      last <- =                 ///
///                                                                          ///
///--------------------------------------------[ v 4.0 in0k © 29.05.2013 ]---//}
{%region /fold 'check "define" for all used macros                     ' }
    //--- VARs
    {$if defined (_M_protoInkFIFO_05v2__cst_STACK)}
        {$define _cst_piFifo05v2_STACK:=_M_protoInkFIFO_05v2__cst_STACK}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_05v2__out_LAST)}
        {$define _out_piFifo05v2_LAST:=_M_protoInkFIFO_05v2__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_05v2__out_COUNT)}
        {$define _out_piFifo05v2_COUNT:=_M_protoInkFIFO_05v2__out_COUNT}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_05v2__lcl_getNext)}
        {$define _fnc_piFifo05v2_getNext:=_M_protoInkFIFO_05v2__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifo05v2_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
    {$ifDef inkFIFO_fncHeadMessage}{$message 'inline -> protoInkLLc_bodyFNC_05v2__getLast'}{$endIF}
    {$deFine _M_protoInkLLc_05v2__cst_FIRST  :=_cst_piFifo05v2_STACK}
    {$deFine _M_protoInkLLc_05v2__out_LAST   :=_out_piFifo05v2_LAST}
    {$deFine _M_protoInkLLc_05v2__out_COUNT  :=_out_piFifo05v2_COUNT}
    {$deFine _M_protoInkLLc_05v2__lcl_getNext:=_fnc_piFifo05v2_getNext}
    {$I protoInkLLc_bodyFNC_05v2__getLast.inc}
end;
{%region /fold 'unDEF used macros                                      ' }
    //--- undef Local macros
    {$unDef _cst_piFifo05v2_STACK}
    {$unDef _out_piFifo05v2_LAST}
    {$unDef _out_piFifo05v2_COUNT}
    {$unDef _fnc_piFifo05v2_getNext}
    //--- undef user
    {$unDef _M_protoInkFIFO_05v2__cst_STACK}
    {$unDef _M_protoInkFIFO_05v2__out_LAST}
    {$unDef _M_protoInkFIFO_05v2__out_COUNT}
    {$unDef _M_protoInkFIFO_05v2__lcl_getNext}
{%endregion 'unDEF used macros' /fold}

