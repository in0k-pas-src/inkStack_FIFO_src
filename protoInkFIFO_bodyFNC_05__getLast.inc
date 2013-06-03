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
    {$if defined (_M_protoInkFIFO_05__cst_STACK)}
        {$define _cst_piFifo05_STACK:=_M_protoInkFIFO_05__cst_STACK}
    {$else}
        {$FATAL 'macro ".._FIRST" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_05__out_LAST)}
        {$define _out_piFifo05_LAST:=_M_protoInkFIFO_05__out_LAST}
    {$else}
        {$FATAL 'macro ".._LAST" : NOT define!'}
    {$endif}
{%endregion 'check "define" for all used macros' /fold}
begin
   _out_piFifo05_LAST:=_cst_piFifo05_STACK;
end;
{%region /fold 'unDEF used macros                                      ' }
    //--- undef Local macros
    {$unDef _cst_piFifo05_STACK}
    {$unDef _out_piFifo05_LAST}
    //--- undef user
    {$unDef _M_protoInkFIFO_05__cst_STACK}
    {$unDef _M_protoInkFIFO_05__out_LAST}
{%endregion 'unDEF used macros' /fold}

