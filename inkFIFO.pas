unit inkFIFO;
{<*** Stack FIFO [ mangust © 29.01.2010 ]
    * работа со стеком FIFO
    *}
{//-----------------------------------------------[ mangust © 29.01.2010 ]---///
///                            _____ _ ___                                   ///
///                  _     _  |   __|_|  _|___last -> -                      ///
///                 |_|___| |_|   __| |  _| . | first -                      ///
///                 | |   | '_|__|  |_|_| |___|       -                      ///
///                 |_|_|_|_,_|    v 4.0      last <- =                      ///
///                                                                          ///
///--------------------------------------------[ v 4.0 in0k © 29.05.2013 ]---//}
///  постоен на КОЛЬЦЕВОМ связном списке (inkLL_cir)
///--------------------------------------------------------------------------///
{краткое содержание повествования:                                      []

  #1 объявление типов
  ===================
    см. inkStack_node.

  #2 работа со списком
  ====================

    -- 2.00-FF рождение и смерть
    00    - создание/инициализация
    --
    FEx1  - уничтожение pInkStack, содержимое пользовательской функцией
    FEx2  - уничтожение pInkStack, содержимое пользовательским методом
    FD    - уничтожение pInkStack, содержимого как tObject
    FFx0  - очистка pInkStack, данные остаются НЕ тронутыми
    FFx1  - уничтожение стека, удаление узла пользовательской функцией
    FFx2  - уничтожение стека, удаление узла пользовательским методом

    -- 2.2 текущие/очевидные свойства списка
    10    - проверка на пустоту
    11    - количесво узлов

    -- 2.3 от кончика ушей до пят (операции над ВСЕМ списком)
    20    - обход списка (с первого по последний)
    20x1  - обход списка с вызовом-по-указателю функции
    20x2  - обход списка вызовом-по-указателю МЕТОДА класса
    69    - инвертирование списка TODO

    -- 2.5 последний Герой (последний узел списка)
    05    - последний Узел

    -- 2.6 вырезать "МЕНЯ"
    C0v1  - вырезать УЗЕЛ (САМОГО СЕБЯ)
    C0v2  - вырезать УЗЕЛ (САМОГО СЕБЯ) и подтверждение и вырезании
    CDv0  - вырезать и вернуть УЗЕЛ с данными
    CDv1  - вырезать ДАННЫЕ (уничтожить узел)
    CDv2  - вырезать ДАННЫЕ (уничтожить узел)

    -- 2.7 Грива и Хвост (вставка/удаление из начала и конца очереди)
        TODO

    -- 2.8 МАССИВ
        TODO

    -- 2.9 СТЕК
    51v0  - положить УЗЕЛ (push)
    51v1  - положить ДВННЫЕ (push)
    5Cv0  - забрать УЗЕЛ (pop)
    5Cv1  - забрать ДВННЫЕ (pop)



//---------------------------------------------------------------------------//}
interface
{%region /fold}//----------------------------------[ compiler directives ]
{}  {$ifdef fpc}                                             { это для LAZARUS }
{}     {$mode delphi}     // для пущей совместимости написанного кода         {}
{}     {$define _INLINE_}                                                     {}
{}  {$else}                                                   { это для DELPHI }
{}     {$IFDEF SUPPORTS_INLINE}                                               {}
{}       {$define _INLINE_}                                                   {}
{}     {$endif}                                                               {}
{}  {$endif}                                                                  {}
{}  {$ifOpt D+} // режим дебуга ВКЛЮЧЕН                      { "боевой" INLINE }
{}       {$undef _INLINE_} // дeбугить просче БЕЗ INLIN`а                     {}
{}  {$endif}                                                                  {}
{%endregion}//-------------------------------------------[ compiler directives ]

{$define _INLINE_}
{$ifOpt D+}
{$define inkFIFO_fncHeadMessage} //< сообщения о текущей процедуре, с ними проще ловить ошибки
{$endif}
uses {$ifOpt D+}sysutils,{$endif} //< попытка отлова ДИНАМИЧЕСКИХ ошибок
    inkStack_node;


type
  fInkFIFO_Destroy=fInkStack_Destroy;
  aInkFIFO_Destroy=aInkStack_Destroy;
  fInkFIFO_Process=fInkStack_Process;
  aInkFIFO_Process=aInkStack_Process;

//****************************************************************************//
//                                                                            //
//                                                                   ЧАСТЬ #2 //
//                                                                            //
//****************************************************************************//

//== 2.0-F рождение и смерть ==

procedure inkFIFO_INIT    (out Stack:pointer);                                  {$ifdef _INLINE_} inline; {$endif}

procedure inkFIFO_CLEAR   (var Stack:pInkStack; const CallBack:fInkFIFO_Destroy);{$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_CLEAR   (var Stack:pInkStack; const CallBack:aInkFIFO_Destroy);{$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_ClearOBJ(var Stack:pInkStack);                                 {$ifdef _INLINE_} inline; {$endif}
procedure inkFIFO_Clean   (var Stack:pInkStack);                                 {$ifdef _INLINE_} inline; {$endif}
procedure inkFIFO_nodesCLR(var Stack:pointer;   const CallBack:fInkFIFO_Destroy);{$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_nodesCLR(var Stack:pointer;   const CallBack:aInkFIFO_Destroy);{$ifdef _INLINE_} inline; {$endif} overload;

procedure inkFIFO_Erase   (var Stack:pointer; const CmpCXT:pointer; const CmpFNC:fInkFIFO_Process; const DspPRC:fInkFIFO_Destroy); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_Erase   (var Stack:pointer; const CmpCXT:pointer; const CmpFNC:aInkFIFO_Process; const DspPRC:aInkFIFO_Destroy); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_nodesERS(var Stack:pointer; const CmpCXT:pointer; const CmpFNC:fInkFIFO_Process; const DspPRC:fInkFIFO_Destroy); {$ifdef _INLINE_} inline; {$endif} overload;
procedure inkFIFO_nodesERS(var Stack:pointer; const CmpCXT:pointer; const CmpFNC:aInkFIFO_Process; const DspPRC:aInkFIFO_Destroy); {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.2 текущие/очевидные свойства списка ==

function  inkFIFO_isEmpty(const Stack:pointer):boolean;                         {$ifdef _INLINE_} inline; {$endif}
function  inkFIFO_Count  (const Stack:pointer):tInkStackCount;                  {$ifdef _INLINE_} inline; {$endif}

//== 2.3 от кончика ушей до пят (операции над ВСЕМ списком) ==

function  inkFIFO_Enumerate(const Stack:pInkStack; const Context:pointer; const EnumFNC:fInkFIFO_Process):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
function  inkFIFO_Enumerate(const Stack:pInkStack; const Context:pointer; const EnumFNC:aInkFIFO_Process):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
function  inkFIFO_nodesEnum(const Stack:pointer;   const Context:pointer; const EnumFNC:fInkFIFO_Process):pointer; {$ifdef _INLINE_} inline; {$endif} overload;
function  inkFIFO_nodesEnum(const Stack:pointer;   const Context:pointer; const EnumFNC:aInkFIFO_Process):pointer; {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.5 последний Герой (последний узел списка) ==

function  inkFIFO_nodeGetLast(const Stack:pointer):pointer;                     {$ifdef _INLINE_} inline; {$endif} overload;

//== 2.6 вырезать "МЕНЯ" ==

function  inkFIFO_cutNodeDATA(var Stack:pInkStack; const DATA:pointer):pInkNodeStack;{$ifdef _INLINE_} inline; {$endif}

procedure inkFIFO_CUT        (var Stack:pInkStack; const DATA:pointer);         {$ifdef _INLINE_} inline; {$endif}
function  inkFIFO_CutRES     (var Stack:pInkStack; const DATA:pointer):boolean; {$ifdef _INLINE_} inline; {$endif}

procedure inkFIFO_nodeCUT    (var Stack:pointer;   const Node:pointer);         {$ifdef _INLINE_} inline; {$endif}
function  inkFIFO_nodeCutRES (var Stack:pointer;   const Node:pointer):boolean; {$ifdef _INLINE_} inline; {$endif}

//== 2.9 СТЕК ==

procedure inkFIFO_PUSH    (var Stack:pInkStack; const DATA:pointer);            {$ifdef _INLINE_} inline; {$endif}
function  inkFIFO_POP     (var Stack:pInkStack):pointer;                        {$ifdef _INLINE_} inline; {$endif}

procedure inkFIFO_nodePUSH(var Stack:pointer; const Node:pointer);              {$ifdef _INLINE_} inline; {$endif}
function  inkFIFO_nodePOP (var Stack:pointer):pointer;                          {$ifdef _INLINE_} inline; {$endif}

implementation

//****************************************************************************//
//                                                                            //
//                                                                   ЧАСТЬ #0 //
//                                                                            //
//****************************************************************************//

{$MACRO ON} // определяем БАЗОВЫЕ макросы
{$deFine _M_protoInkFIFO_blockFNK__GetNext:=InkNodeStack_getNext}
{$deFine _M_protoInkFIFO_blockFNK__SetNext:=InkNodeStack_setNext}
{$deFine _M_protoInkFIFO_blockFNK__GetDATA:=InkNodeStack_getDATA}

//****************************************************************************//
//                                                                            //
//                                                                   ЧАСТЬ #2 //
//                                                                            //
//****************************************************************************//

{:::[00] ИНИЦИАЛИЗИРОВАТЬ, подготовить к работе.
  @param(Stack указатель на cтек [на первый узел])
  :}
procedure inkFIFO_INIT(out Stack:pointer);
begin
    Stack:=NIL;
end;

//------------------------------------------------------------------------------

{:::[FEx1] УНИЧТОЖИТЬ стек. [CallBack(pInkNodeStack(Node)^.DATA)]
  уничтожить содержимое элементов стека пользовательской ф-цией CallBack,
  а сами элементы ф-цией InkNodeStack_Destroy.
  @param(Stack указатель на cтек [на первый узел])
  @param(CallBack ФУНКЦИЯ для уничтожения данных pInkNodeStack^.DATA)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_CLEAR(var Stack:pInkStack; const CallBack:fInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_CLEAR function'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FE__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FE__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FE__lcl_dataDST:=CallBack}
{$deFine _M_protoInkFIFO_FE__lcl_nodeDST:=inkNodeStack_DESTROY}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FE__Clear.inc}
end;

{:::[FEx2] УНИЧТОЖИТЬ стек. [CallBack(pInkNodeStack(Node)^.DATA)]
  уничтожить содержимое элементов стека пользовательской ф-цией CallBack,
  а сами элементы ф-цией InkNodeStack_Destroy.
  @param(Stack указатель на cтек [на первый узел])
  @param(CallBack МЕТОД для уничтожения данных pInkNodeStack^.DATA)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_CLEAR(var Stack:pInkStack; const CallBack:aInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_CLEAR method'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FE__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FE__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FE__lcl_dataDST:=CallBack}
{$deFine _M_protoInkFIFO_FE__lcl_nodeDST:=inkNodeStack_DESTROY}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FE__Clear.inc}
end;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[FD] УНИЧТОЖИТЬ стек. [tObject(pInkNodeStack(Node)^.DATA).FREE]
  уничтожить содержимое элементов стека как tObject,
  а сами элементы ф-цией InkNodeStack_Destroy.
  @param(Stack указатель на cтек [на первый узел])
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_clearOBJ(var Stack:pInkStack);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_clearOBJ'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FD__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FD__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FD__lcl_nodeDST:=InkNodeStack_Destroy}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FD__ClearOBJ.inc}
end;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[FFx0] ОЧИСТИТЬ стек.
  уничтожить ТОЛЬКО элементы стека. Для КАЖДОГО элемента будет вызванна
  процедура InkNodeStack_Destroy(Node).
  @param(Stack указатель на cтек [на первый узел])
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_clean(var Stack:pInkStack);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_clean function'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FF__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FF__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FF__lcl_nodeDST:=InkNodeStack_Destroy}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FF__Clear.inc}
end;

//------------------------------------------------------------------------------

{:::[FFx1] УНИЧТОЖИТЬ стек. [CallBack(Node)]
  уничтожить элементы стека пользовательской ф-цией CallBack.
  @param(Stack указатель на cтек [на первый узел])
  @param(CallBack ФУНКЦИЯ для уничтожения узла)
  ---
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_nodesCLR(var Stack:pointer; const CallBack:fInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesCLR function'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FF__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FF__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FF__lcl_nodeDST:=CallBack}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FF__CLEAR.inc}
end;

{:::[FFx2] УНИЧТОЖИТЬ стек.
  уничтожить элементы стека вместе с информацией.
  Для КАЖДОГО элемента будет вызванна процедура CallBack(Node), в которой
  необходимо уничтожить как САМ элемент, так и ИНФОРМАЦИЮ связянную с ним.
  @param(Stack указатель на cтек [на первый узел])
  @param(CallBack МЕТОД для уничтожения узла)
  ---
  * после выполнения Stack===@nil
  :}
procedure inkFIFO_nodesCLR(var Stack:pointer; const CallBack:aInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesCLR method'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_FF__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_FF__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_FF__lcl_nodeDST:=CallBack}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_FF__CLEAR.inc}
end;

//==============================================================================

procedure inkFIFO_Erase(var Stack:pointer; const CmpCXT:pointer; const CmpFNC:fInkFIFO_Process; const DspPRC:fInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesERS function'}{$endIF}
var tmp,tmq:pointer;
procedure _inkFIFO_Erase_nodeDST_(const Node:pointer); inline;
begin
    DspPRC(InkNodeStack_getDATA(Node));
    InkNodeStack_Destroy(Node);
end;
function _inkFIFO_Erase_nodeCMP_(const Context:pointer; const Node:pointer):boolean; inline;
begin
    result:=CmpFNC(Context,InkNodeStack_getDATA(Node));
end;
{$deFine _m_protoInkFIFO_E4__tmp_POINTER0:=tmp}
{$deFine _M_protoInkFIFO_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkFIFO_E4__var_STACK   :=Stack}
{$deFine _M_protoInkFIFO_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkFIFO_E4__lcl_cmpFNC  :=_inkFIFO_Erase_nodeCMP_}
{$deFine _M_protoInkFIFO_E4__lcl_dspPRC  :=_inkFIFO_Erase_nodeDST_}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_E4__Erase.inc}
end;

procedure inkFIFO_Erase(var Stack:pointer; const CmpCXT:pointer; const CmpFNC:aInkFIFO_Process; const DspPRC:aInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesERS function'}{$endIF}
var tmp,tmq:pointer;
procedure _inkFIFO_Erase_nodeDST_(const Node:pointer); inline;
begin
    DspPRC(InkNodeStack_getDATA(Node));
    InkNodeStack_Destroy(Node);
end;
function _inkFIFO_Erase_nodeCMP_(const Context:pointer; const Node:pointer):boolean; inline;
begin
    result:=CmpFNC(Context,InkNodeStack_getDATA(Node));
end;
{$deFine _m_protoInkFIFO_E4__tmp_POINTER0:=tmp}
{$deFine _M_protoInkFIFO_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkFIFO_E4__var_STACK   :=Stack}
{$deFine _M_protoInkFIFO_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkFIFO_E4__lcl_cmpFNC  :=_inkFIFO_Erase_nodeCMP_}
{$deFine _M_protoInkFIFO_E4__lcl_dspPRC  :=_inkFIFO_Erase_nodeDST_}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_E4__Erase.inc}
end;

procedure inkFIFO_nodesERS(var  Stack:pointer; const CmpCXT:pointer; const CmpFNC:fInkFIFO_Process; const DspPRC:fInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesERS function'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkFIFO_E4__tmp_POINTER0:=tmp}
{$deFine _M_protoInkFIFO_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkFIFO_E4__var_STACK   :=Stack}
{$deFine _M_protoInkFIFO_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkFIFO_E4__lcl_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkFIFO_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_E4__Erase.inc}
end;

procedure inkFIFO_nodesERS(var  Stack:pointer; const CmpCXT:pointer; const CmpFNC:aInkFIFO_Process; const DspPRC:aInkFIFO_Destroy);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesERS function'}{$endIF}
var tmp,tmq:pointer;
{$deFine _m_protoInkFIFO_E4__tmp_POINTER0:=tmp}
{$deFine _M_protoInkFIFO_E4__tmp_POINTER1:=tmq}
{$deFine _M_protoInkFIFO_E4__var_STACK   :=Stack}
{$deFine _M_protoInkFIFO_E4__cst_cmpCTX  :=CmpCXT}
{$deFine _M_protoInkFIFO_E4__lcl_cmpFNC  :=CmpFNC}
{$deFine _M_protoInkFIFO_E4__lcl_dspPRC  :=DspPRC}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_E4__Erase.inc}
end;

//==============================================================================

{:::[10] очередь ПУСТая?
  @param(Stack указатель на cтек [на первый узел])
  @return(@true -- да, очередь Пуста; @false -- ЕСТЬ элементы)
  :}
function inkFIFO_isEmpty(const Stack:pointer):boolean;
begin
    result:= Stack=nil;
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[11] ПОсчитать количество узлов (путем прямого перебора)
  @param(Stack указатель на cтек [на первый узел])
  @return(количество узлов)
  :}
function inkFIFO_Count(const Stack:pointer):tInkStackCount;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_Count'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_11__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_11__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_11__out_COUNT  :=result}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_11__Count.inc}
end;

//==============================================================================

{:::[20x1] ОБОЙТИ стек [EnumFNC(Context,pInkNodeStack(Node)^.DATA)].
  Посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ, для КАЖДОГО узла
  будет вызванна пользовательская ф-ция в которую передается СОДЕРЖИМОЕ
  элемента стека.
  @param(Stack указатель на cтек [на первый узел])
  @param(Context контекст выполнения ф-ции EnumFNC)
  @param(EnumFNC "сallBack" ФУНКЦИЯ вызываемая для КАЖДОГО узла)
  @return(@nil -- ВСё обошли; иначе указатель на последние посещенные ДАННЫЕ)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
function inkFIFO_Enumerate(const Stack:pInkStack; const Context:pointer; const EnumFNC:fInkFIFO_Process):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_Enumerate function'}{$endIF}
{$deFine _M_protoInkFIFO_20__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_20__cst_context:=Context}
{$deFine _M_protoInkFIFO_20__cst_enumFNC:=EnumFNC}
{$deFine _M_protoInkFIFO_20__out_LAST   :=result}
{$deFine _M_protoInkFIFO_20__lcl_preENUM:=InkNodeStack_getDATA}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_20__Enumerate.inc}
end;

{:::[20x1] ОБОЙТИ стек [EnumFNC(Context,pInkNodeStack(Node)^.DATA)].
  Посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ, для КАЖДОГО узла
  будет вызванна пользовательская ф-ция в которую передается СОДЕРЖИМОЕ
  элемента стека.
  @param(Stack указатель на cтек [на первый узел])
  @param(Context контекст выполнения ф-ции EnumFNC)
  @param(EnumFNC "сallBack" МЕТОД вызываемый для КАЖДОГО узла)
  @return(@nil -- ВСё обошли; иначе указатель на последние посещенные ДАННЫЕ)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
function inkFIFO_Enumerate(const Stack:pInkStack; const Context:pointer; const EnumFNC:aInkFIFO_Process):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_Enumerate method'}{$endIF}
{$deFine _M_protoInkFIFO_20__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_20__cst_context:=Context}
{$deFine _M_protoInkFIFO_20__cst_enumFNC:=EnumFNC}
{$deFine _M_protoInkFIFO_20__out_LAST   :=result}
{$deFine _M_protoInkFIFO_20__lcl_preENUM:=InkNodeStack_getDATA}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_20__Enumerate.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[20x3] ОБОЙТИ стек [EnumFNC(Context,NODE)].
  Посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ, для КАЖДОГО узла
  будет вызванна пользовательская ф-ция в которую передается САМ элемента стека.
  @param(Stack указатель на cтек [на первый узел])
  @param(Context контекст выполнения ф-ции EnumFNC)
  @param(EnumFNC "сallBack" ФУНКЦИЯ вызываемая для КАЖДОГО узла)
  @return(@nil -- ВСё обошли; иначе указатель на последний посещенный УЗЕЛ)
  :}
function inkFIFO_nodesEnum(const Stack:pointer; const Context:pointer; const EnumFNC:fInkFIFO_Process):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesEnum function'}{$endIF}
{$deFine _M_protoInkFIFO_20__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_20__cst_context:=Context}
{$deFine _M_protoInkFIFO_20__cst_enumFNC:=EnumFNC}
{$deFine _M_protoInkFIFO_20__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_20__Enumerate.inc}
end;

{:::[20x4] ОБОЙТИ стек [EnumFNC(Context,NODE)].
  Посетить КАЖДЫЙ узел в порядке с ПЕРВОГО по ПОСЛЕДНИЙ, для КАЖДОГО узла
  будет вызванна пользовательская ф-ция в которую передается САМ элемента стека.
  @param(Stack указатель на cтек [на первый узел])
  @param(Context контекст выполнения ф-ции EnumFNC)
  @param(EnumFNC "сallBack" МЕТОД вызываемый для КАЖДОГО узла)
  @return(@nil -- ВСё обошли; иначе указатель на последний посещенный УЗЕЛ)
  :}
function inkFIFO_nodesEnum(const Stack:pointer; const Context:pointer; const EnumFNC:aInkFIFO_Process):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodesEnum method'}{$endIF}
{$deFine _M_protoInkFIFO_20__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_20__cst_context:=Context}
{$deFine _M_protoInkFIFO_20__cst_enumFNC:=EnumFNC}
{$deFine _M_protoInkFIFO_20__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_20__Enumerate.inc}
end;

//==============================================================================

{:::[05v1] последний УЗЕЛ стека (путем прямого перебора)
  @param(Stack указатель на cтек [на первый узел])
  @return(указатель на ПОСЛЕДНИЙ узел стека)
  :}
function inkFIFO_nodeGetLast(const Stack:pointer):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodeGetLast'}{$endIF}
{$deFine _M_protoInkFIFO_05__cst_STACK  :=Stack}
{$deFine _M_protoInkFIFO_05__out_LAST   :=result}
begin //< для удобства навигации
{$I protoInkFIFO_bodyFNC_05__getLast.inc}
end;

//==============================================================================

{:::[CDv0] вырезать УЗЕЛ стека содержащий информацию
  @param(Stack указатель на cтек [на первый узел])
  @param(DATA содержимое, элемент с которым должны вырезать)
  @return(@nil -- узла с таким содержимым НЕТ; вырезанный УЗЕЛ)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
function inkFIFO_cutNodeDATA(var Stack:pInkStack; const DATA:pointer):pInkNodeStack;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_cutNodeDATA'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkFIFO_CDv0__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_CDv0__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_CDv0__cst_DATA   :=DATA}
{$deFine _M_protoInkFIFO_CDv0__out_RES    :=result}
begin
{$I protoInkFIFO_bodyFNC_CDv0__cutNodeDATA.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[CDv1] вырезать ДАННЫЕ.
  найти и УНИЧТОЖЫТЬ УЗЕЛ стека содержащий информацию
  @param(Stack указатель на cтек [на первый узел])
  @param(DATA содержимое, элемент с которым должны уничтожить)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
procedure inkFIFO_CUT(var Stack:pInkStack; const DATA:pointer);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_CUT'}{$endIF}
var tmp:pointer;
    tmq:pointer;
{$deFine _M_protoInkFIFO_CDv1__tmp_POINTER_01:=tmp}
{$deFine _M_protoInkFIFO_CDv1__tmp_POINTER_02:=tmq}
{$deFine _M_protoInkFIFO_CDv1__var_STACK     :=Stack}
{$deFine _M_protoInkFIFO_CDv1__cst_DATA      :=DATA}
{$deFine _M_protoInkFIFO_CDv1__out_RES       :=result}
{$deFine _M_protoInkFIFO_CDv1__lcl_nodeDST   :=InkNodeStack_Destroy}
begin
{$I protoInkFIFO_bodyFNC_CDv1__cutNodeDATA.inc}
end;

{:::[CDv1] вырезать ДАННЫЕ.
  найти и УНИЧТОЖЫТЬ УЗЕЛ стека содержащий информацию
  @param(Stack указатель на cтек [на первый узел])
  @param(DATA содержимое, элемент с которым должны уничтожить)
  @return(@true -- УЗЕЛ с такими данными был найден и уничтожен, т.е. ДАННЫЕ
          вырезаны из стека; @false -- элемента с такими данными НЕ найденно)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
function inkFIFO_CutRES(var Stack:pInkStack; const DATA:pointer):boolean;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_CutRES'}{$endIF}
var tmp:pointer;
    tmq:pointer;
{$deFine _M_protoInkFIFO_CDv2__tmp_POINTER_01:=tmp}
{$deFine _M_protoInkFIFO_CDv2__tmp_POINTER_02:=tmq}
{$deFine _M_protoInkFIFO_CDv2__var_STACK     :=Stack}
{$deFine _M_protoInkFIFO_CDv2__cst_DATA      :=DATA}
{$deFine _M_protoInkFIFO_CDv2__out_RES       :=result}
{$deFine _M_protoInkFIFO_CDv2__lcl_nodeDST   :=InkNodeStack_Destroy}
begin
{$I protoInkFIFO_bodyFNC_CDv2__cutNodeDATA.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[C0v1] вырезать УЗЕЛ.
  найти и ВЫРЕЗАТЬ из стека УЗЕЛ
  @param(Stack указатель на cтек [на первый узел])
  @param(Node ВЫРЕЗАЕМЫЙ элемент списка)
  :}
procedure inkFIFO_nodeCUT(var Stack:pointer; const Node:pointer);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodeCUT'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkFIFO_C0v1__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_C0v1__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_C0v1__cst_NODE   :=Node}
begin
{$I protoInkFIFO_bodyFNC_C0v1__cutNode.inc}
end;

{:::[C0v2] вырезать УЗЕЛ.
  найти и ВЫРЕЗАТЬ из стека УЗЕЛ
  @param(Stack указатель на cтек [на первый узел])
  @param(Node ВЫРЕЗАЕМЫЙ элемент списка)
  @return(@true -- УЗЕЛ найден и вырезан из стека; @false -- не нашлось)
  :}
function inkFIFO_nodeCutRES(var Stack:pointer; const Node:pointer):boolean;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodeCutRES'}{$endIF}
var tmp:pointer;
{$deFine _M_protoInkFIFO_C0v2__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_C0v2__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_C0v2__cst_NODE   :=Node}
{$deFine _M_protoInkFIFO_C0v2__out_RES    :=result}
begin
{$I protoInkFIFO_bodyFNC_C0v2__cutNode.inc}
end;

//==============================================================================

{:::[51v1] положить ДАННЫЕ в стек.
  создать УЗЕЛ стека (pInkNodeStack), вложить в него данные и положить в СТЕК
  @param(Stack указатель на cтек [на первый узел])
  @param(DATA данные РАЗМЕЩАЕМЫЕ в стеке)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
procedure inkFIFO_PUSH(var Stack:pInkStack; const DATA:pointer);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_PUSH'}{$endIF}
{$deFine _M_protoInkFIFO_51v1__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_51v1__cst_DATA   :=DATA}
{$deFine _M_protoInkFIFO_51v1__lcl_nodeCRT:=InkNodeStack_Create}
begin
{$I protoInkFIFO_bodyFNC_51v1__dataPUSH.inc}
end;

{:::[5Сv1] забрать ДАННЫЕ из стека.
  вырезаем и УНИЧТОЖАТЕМ первый элемент стека (pInkNodeStack)
  @param(Stack указатель на cтек [на первый узел])
  @return(указатель на ДАННЫЕ, которые лежали в ПЕРВОМ элементе)
  ---
  * стек ДОЛЖЕН быть построен на типе pInkNodeStack
  :}
function  inkFIFO_POP (var Stack:pInkStack):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_POP'}{$endIF}
var tmp:pointer;
{$deFine _m_protoInkFIFO_5Cv1__tmp_POINTER:=tmp}
{$deFine _M_protoInkFIFO_5Cv1__var_STACK  :=Stack}
{$deFine _M_protoInkFIFO_5Cv1__out_DATA   :=result}
{$deFine _M_protoInkFIFO_5Cv1__lcl_nodeDST:=inkNodeStack_DESTROY}
begin
{$I protoInkFIFO_bodyFNC_5Cv1__dataPOP.inc}
end;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

{:::[51v0] положить УЗЕЛ в стек.
  положить ГОТОВЫЙ узел на вершину стека.
  @param(Stack указатель на cтек [на первый узел])
  @param(Node узел РАЗМЕЩАЕМЫЙ в стеке)
  :}
procedure inkFIFO_nodePUSH(var Stack:pointer; const Node:pointer);
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodePUSH'}{$endIF}
{$deFine _M_protoInkFIFO_51v0__var_STACK:=Stack}
{$deFine _M_protoInkFIFO_51v0__cst_NODE :=NODE}
begin
{$I protoInkFIFO_bodyFNC_51v0__nodePUSH.inc}
end;

{:::[5сv0] забрать УЗЕЛ из стека.
  вырезать и вернуть узел лежащий на вершине стека.
  @param(Stack указатель на cтек [на первый узел])
  @return(указатель на УЗЕЛ, который БЫЛ первым элементом)
  :}
function inkFIFO_nodePOP(var Stack:pointer):pointer;
{$ifDef inkFIFO_fncHeadMessage}{$message 'inkFIFO_nodePOP'}{$endIF}
{$deFine _M_protoInkFIFO_5Cv0__var_STACK:=Stack}
{$deFine _M_protoInkFIFO_5Cv0__out_NODE :=result}
begin
{$I protoInkFIFO_bodyFNC_5Cv0__nodePOP.inc}
end;

end.
