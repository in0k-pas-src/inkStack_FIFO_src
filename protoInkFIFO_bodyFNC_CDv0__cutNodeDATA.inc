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
    {$if defined (_M_protoInkFIFO_CDv0__var_STACK)}
        {$define _var_piFifoCDv0_STACK:=_M_protoInkFIFO_CDv0__var_STACK}
    {$else}
        {$FATAL 'macro ".._STACK" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv0__cst_DATA)}
        {$define _cst_piFifoCDv0_DATA:=_M_protoInkFIFO_CDv0__cst_DATA}
    {$else}
        {$FATAL 'macro ".._NODE" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv0__out_RES)}
        {$define _out_piFifoCDv0_RES:=_M_protoInkFIFO_CDv0__out_RES}
    {$else}
        {$FATAL 'macro ".._RES" : NOT define!'}
    {$endif}
    //--- FNCs
    {$if defined (_M_protoInkFIFO_CDv0__lcl_getNext)}
        {$define _fnc_piFifoCDv0_getNext:=_M_protoInkFIFO_CDv0__lcl_getNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetNext)}
        {$define _fnc_piFifoCDv0_getNext:=_M_protoInkFIFO_blockFNK__GetNext}
    {$else}
        {$FATAL 'macro ".._getNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv0__lcl_setNext)}
        {$define _prc_piFifoCDv0_setNext:=_M_protoInkFIFO_CDv0__lcl_setNext}
    {$elseif defined (_M_protoInkFIFO_blockFNK__SetNext)}
        {$define _prc_piFifoCDv0_setNext:=_M_protoInkFIFO_blockFNK__SetNext}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
    //---
    {$if defined (_M_protoInkFIFO_CDv0__lcl_getDATA)}
        {$define _fnc_piFifoCDv0_getDATA:=_M_protoInkFIFO_CDv0__lcl_getDATA}
    {$elseif defined (_M_protoInkFIFO_blockFNK__GetDATA)}
        {$define _fnc_piFifoCDv0_getDATA:=_M_protoInkFIFO_blockFNK__GetDATA}
    {$else}
        {$FATAL 'macro ".._setNext" : NOT define!'}
    {$endif}
{%endregion}
{%region /fold 'setUP local vars'                                        }
{$if defined (_m_protoInkFIFO_CDv0__tmp_POINTER)}
    {$define _tmp_piFifoCDv0_POINTER:=_m_protoInkFIFO_CDv0__tmp_POINTER}
{$else}
var tmp:pointer;
    {$define _tmp_piFifoCDv0_POINTER:=tmp}
{$endif}
{%endregion}
begin
    //-- проверки
    {$ifOpt D+}
        {$if defined (_M_protoInkLLs_blockFNK__GetNext)}
            if _cst_piLLcCDv0_DATA=nil then begin
                raise Exception.CReate('_cst_piLLcCDv0_DATA==nil !!!');
            end;
        {$endif}
    {$endif}
    //-- агоритм-ритм-ритм
    if _var_piFifoCDv0_STACK<>nil then begin //< имеет ли смысл работать
        if _fnc_piFifoCDv0_getNext(_var_piFifoCDv0_STACK)<>_var_piFifoCDv0_STACK then begin //< тоесть больше чем один элемент в списке
            // надо искать ПРЕДЫДУЩИЙ относительно _cst_piLLcCDv0_DATA
           _tmp_piFifoCDv0_POINTER:=_var_piFifoCDv0_STACK;
           _out_piFifoCDv0_RES   :=_fnc_piFifoCDv0_getNext(_tmp_piFifoCDv0_POINTER);
            while (_out_piFifoCDv0_RES<>nil)and
                  (_fnc_piFifoCDv0_getDATA(_out_piFifoCDv0_RES)<>_cst_piFifoCDv0_DATA)
            do begin
                if _out_piFifoCDv0_RES=_var_piFifoCDv0_STACK then begin
                   _out_piFifoCDv0_RES:=nil;
                    break;
                end;
               _tmp_piFifoCDv0_POINTER:=_out_piFifoCDv0_RES;
               _out_piFifoCDv0_RES   :=_fnc_piFifoCDv0_getNext(_tmp_piFifoCDv0_POINTER);
            end;
            if _out_piFifoCDv0_RES<>nil then begin //< таки нашли
               _prc_piFifoCDv0_setNext(_tmp_piFifoCDv0_POINTER, _fnc_piFifoCDv0_getNext(_out_piFifoCDv0_RES));
                // а если, то фиксим указатель
                if _var_piFifoCDv0_STACK=_out_piFifoCDv0_RES
                then _var_piFifoCDv0_STACK:=_fnc_piFifoCDv0_getNext(_out_piFifoCDv0_RES);
            end;
        end
       else
        if _fnc_piFifoCDv0_getDATA(_var_piFifoCDv0_STACK)=_cst_piFifoCDv0_DATA then begin
            // тоесть список из ОДНОГО элемента, и его надо вырезать
           _out_piFifoCDv0_RES  :=_var_piFifoCDv0_STACK;
           _var_piFifoCDv0_STACK:=NIL;
        end
       else _out_piFifoCDv0_RES:=nil;
    end
    else _out_piFifoCDv0_RES:=NIL;
end;
{%region /fold 'unDEF used macros'                                       }
    //--- undef Supre Local macros
    {$unDef _tmp_piFifoCDv0_POINTER}
    //--- undef Local macros
    {$unDef _var_piFifoCDv0_STACK}
    {$unDef _cst_piFifoCDv0_DATA}
    {$unDef _out_piFifoCDv0_RES}
    {$unDef _fnc_piFifoCDv0_getNext}
    {$unDef _prc_piFifoCDv0_setNext}
    {$unDef _fnc_piFifoCDv0_getDATA}
    //--- undef user
    {$unDef _m_protoInkFIFO_CDv0__tmp_POINTER}
    {$unDef _M_protoInkFIFO_CDv0__var_STACK}
    {$unDef _M_protoInkFIFO_CDv0__cst_DATA}
    {$unDef _M_protoInkFIFO_CDv0__out_RES}
    {$unDef _M_protoInkFIFO_CDv0__lcl_getNext}
    {$unDef _M_protoInkFIFO_CDv0__lcl_setNext}
    {$unDef _M_protoInkFIFO_CDv0__lcl_getDATA}
{%endregion}
