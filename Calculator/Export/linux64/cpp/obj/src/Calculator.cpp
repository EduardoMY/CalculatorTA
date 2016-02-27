#include <hxcpp.h>

#ifndef INCLUDED_Calculator
#include <Calculator.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Calculator_obj::__construct()
{
HX_STACK_FRAME("Calculator","new",0x7bd10b14,"Calculator.new","Calculator.hx",11,0xc727f2dc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(11)
	this->originalOperation = HX_HCSTRING("0","\x30","\x00","\x00","\x00");
}
;
	return null();
}

//Calculator_obj::~Calculator_obj() { }

Dynamic Calculator_obj::__CreateEmpty() { return  new Calculator_obj; }
hx::ObjectPtr< Calculator_obj > Calculator_obj::__new()
{  hx::ObjectPtr< Calculator_obj > _result_ = new Calculator_obj();
	_result_->__construct();
	return _result_;}

Dynamic Calculator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Calculator_obj > _result_ = new Calculator_obj();
	_result_->__construct();
	return _result_;}

Void Calculator_obj::setOperation( ::String newOperation){
{
		HX_STACK_FRAME("Calculator","setOperation",0x84f812f1,"Calculator.setOperation","Calculator.hx",14,0xc727f2dc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(newOperation,"newOperation")
		HX_STACK_LINE(15)
		this->originalOperation = newOperation;
		HX_STACK_LINE(16)
		this->operations = Array_obj< ::String >::__new();
		HX_STACK_LINE(17)
		::String tmp = this->originalOperation;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(17)
		Dynamic tmp1 = this->evaluate(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(17)
		this->result = tmp1;
		HX_STACK_LINE(18)
		int tmp2 = this->result;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(18)
		::String tmp3 = this->getBinaryValue(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(18)
		this->resultBinary = tmp3;
		HX_STACK_LINE(19)
		::String tmp4 = this->resultBinary;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(19)
		::String tmp5 = this->getHexadecimalValue(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(19)
		this->resultHexadecimal = tmp5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,setOperation,(void))

bool Calculator_obj::checkIntegrity( ){
	HX_STACK_FRAME("Calculator","checkIntegrity",0xd82f8871,"Calculator.checkIntegrity","Calculator.hx",22,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(23)
	::String alphabet_0 = HX_HCSTRING("0","\x30","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_0,"alphabet_0");
	HX_STACK_LINE(23)
	::String alphabet_1 = HX_HCSTRING("1","\x31","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_1,"alphabet_1");
	HX_STACK_LINE(23)
	::String alphabet_2 = HX_HCSTRING("2","\x32","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_2,"alphabet_2");
	HX_STACK_LINE(23)
	::String alphabet_3 = HX_HCSTRING("3","\x33","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_3,"alphabet_3");
	HX_STACK_LINE(23)
	::String alphabet_4 = HX_HCSTRING("4","\x34","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_4,"alphabet_4");
	HX_STACK_LINE(23)
	::String alphabet_5 = HX_HCSTRING("5","\x35","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_5,"alphabet_5");
	HX_STACK_LINE(23)
	::String alphabet_6 = HX_HCSTRING("6","\x36","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_6,"alphabet_6");
	HX_STACK_LINE(23)
	::String alphabet_7 = HX_HCSTRING("7","\x37","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_7,"alphabet_7");
	HX_STACK_LINE(23)
	::String alphabet_8 = HX_HCSTRING("8","\x38","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_8,"alphabet_8");
	HX_STACK_LINE(23)
	::String alphabet_9 = HX_HCSTRING("9","\x39","\x00","\x00","\x00");		HX_STACK_VAR(alphabet_9,"alphabet_9");
	HX_STACK_LINE(24)
	::String alphabetOperations_0 = HX_HCSTRING("+","\x2b","\x00","\x00","\x00");		HX_STACK_VAR(alphabetOperations_0,"alphabetOperations_0");
	HX_STACK_LINE(24)
	::String alphabetOperations_1 = HX_HCSTRING("-","\x2d","\x00","\x00","\x00");		HX_STACK_VAR(alphabetOperations_1,"alphabetOperations_1");
	HX_STACK_LINE(24)
	::String alphabetOperations_2 = HX_HCSTRING("*","\x2a","\x00","\x00","\x00");		HX_STACK_VAR(alphabetOperations_2,"alphabetOperations_2");
	HX_STACK_LINE(24)
	::String alphabetOperations_3 = HX_HCSTRING("/","\x2f","\x00","\x00","\x00");		HX_STACK_VAR(alphabetOperations_3,"alphabetOperations_3");
	HX_STACK_LINE(25)
	Array< ::Dynamic > states;		HX_STACK_VAR(states,"states");
	HX_STACK_LINE(26)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(Calculator_obj,checkIntegrity,return )

int Calculator_obj::print( ){
	HX_STACK_FRAME("Calculator","print",0x09d3a7e1,"Calculator.print","Calculator.hx",29,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(30)
	int tmp = this->result;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(30)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Calculator_obj,print,return )

::String Calculator_obj::printBinary( ){
	HX_STACK_FRAME("Calculator","printBinary",0xd88876c2,"Calculator.printBinary","Calculator.hx",33,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	::String tmp = this->resultBinary;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(34)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Calculator_obj,printBinary,return )

::String Calculator_obj::printHexadecimal( ){
	HX_STACK_FRAME("Calculator","printHexadecimal",0x2ad8b1ca,"Calculator.printHexadecimal","Calculator.hx",37,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	::String tmp = this->resultHexadecimal;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(38)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Calculator_obj,printHexadecimal,return )

Array< ::String > Calculator_obj::printOperations( ){
	HX_STACK_FRAME("Calculator","printOperations",0x99eacdad,"Calculator.printOperations","Calculator.hx",42,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(42)
	return this->operations;
}


HX_DEFINE_DYNAMIC_FUNC0(Calculator_obj,printOperations,return )

Dynamic Calculator_obj::evaluate( ::String expression){
	HX_STACK_FRAME("Calculator","evaluate",0x6bddd925,"Calculator.evaluate","Calculator.hx",46,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(expression,"expression")
	HX_STACK_LINE(47)
	Array< ::String > tokens = expression.split(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tokens,"tokens");
	HX_STACK_LINE(48)
	int length = tokens->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(49)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(51)
	Array< int > values = Array_obj< int >::__new();		HX_STACK_VAR(values,"values");
	HX_STACK_LINE(54)
	Array< ::String > ops = Array_obj< ::String >::__new();		HX_STACK_VAR(ops,"ops");
	HX_STACK_LINE(56)
	while((true)){
		HX_STACK_LINE(56)
		bool tmp = (i < length);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(56)
		bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(56)
		if ((tmp1)){
			HX_STACK_LINE(56)
			break;
		}
		HX_STACK_LINE(59)
		::String tmp2 = tokens->__get(i);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(59)
		bool tmp3 = (tmp2 == HX_HCSTRING(" ","\x20","\x00","\x00","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(59)
		if ((tmp3)){
			HX_STACK_LINE(60)
			continue;
		}
		HX_STACK_LINE(63)
		::String tmp4 = tokens->__get(i);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(63)
		bool tmp5 = (tmp4 >= HX_HCSTRING("0","\x30","\x00","\x00","\x00"));		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(63)
		bool tmp6;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(63)
		if ((tmp5)){
			HX_STACK_LINE(63)
			::String tmp7 = tokens->__get(i);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(63)
			::String tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(63)
			tmp6 = (tmp8 <= HX_HCSTRING("9","\x39","\x00","\x00","\x00"));
		}
		else{
			HX_STACK_LINE(63)
			tmp6 = false;
		}
		HX_STACK_LINE(63)
		if ((tmp6)){
			HX_STACK_LINE(65)
			::String stringNumber = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(stringNumber,"stringNumber");
			HX_STACK_LINE(67)
			while((true)){
				HX_STACK_LINE(67)
				bool tmp7 = (i < length);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(67)
				bool tmp8 = tmp7;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(67)
				bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(67)
				if ((tmp8)){
					HX_STACK_LINE(67)
					::String tmp10 = tokens->__get(i);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(67)
					::String tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(67)
					::String tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(67)
					tmp9 = (tmp12 >= HX_HCSTRING("0","\x30","\x00","\x00","\x00"));
				}
				else{
					HX_STACK_LINE(67)
					tmp9 = false;
				}
				HX_STACK_LINE(67)
				bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(67)
				if ((tmp9)){
					HX_STACK_LINE(67)
					::String tmp11 = tokens->__get(i);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(67)
					::String tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(67)
					tmp10 = (tmp12 <= HX_HCSTRING("9","\x39","\x00","\x00","\x00"));
				}
				else{
					HX_STACK_LINE(67)
					tmp10 = false;
				}
				HX_STACK_LINE(67)
				bool tmp11 = !(tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(67)
				if ((tmp11)){
					HX_STACK_LINE(67)
					break;
				}
				HX_STACK_LINE(68)
				int tmp12 = (i)++;		HX_STACK_VAR(tmp12,"tmp12");
				HX_STACK_LINE(68)
				::String tmp13 = tokens->__get(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
				HX_STACK_LINE(68)
				hx::AddEq(stringNumber,tmp13);
			}
			HX_STACK_LINE(69)
			::String tmp7 = stringNumber;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(69)
			Dynamic tmp8 = ::Std_obj::parseInt(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(69)
			values->push(tmp8);
			HX_STACK_LINE(70)
			(i)--;
		}
		else{
			HX_STACK_LINE(74)
			::String tmp7 = tokens->__get(i);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(74)
			bool tmp8 = (tmp7 == HX_HCSTRING("(","\x28","\x00","\x00","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(74)
			if ((tmp8)){
				HX_STACK_LINE(75)
				::String tmp9 = tokens->__get(i);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(75)
				ops->push(tmp9);
			}
			else{
				HX_STACK_LINE(78)
				::String tmp9 = tokens->__get(i);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(78)
				bool tmp10 = (tmp9 == HX_HCSTRING(")","\x29","\x00","\x00","\x00"));		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(78)
				if ((tmp10)){
					HX_STACK_LINE(80)
					while((true)){
						HX_STACK_LINE(80)
						int tmp11 = (ops->length - (int)1);		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(80)
						::String tmp12 = ops->__get(tmp11);		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(80)
						bool tmp13 = (tmp12 != HX_HCSTRING("(","\x28","\x00","\x00","\x00"));		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(80)
						bool tmp14 = !(tmp13);		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(80)
						if ((tmp14)){
							HX_STACK_LINE(80)
							break;
						}
						HX_STACK_LINE(81)
						::String tmp15 = ops->pop();		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(81)
						Dynamic tmp16 = values->pop();		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(81)
						Dynamic tmp17 = values->pop();		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(81)
						int tmp18 = this->applyOp(tmp15,tmp16,tmp17);		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(81)
						values->push(tmp18);
					}
					HX_STACK_LINE(82)
					ops->pop();
				}
				else{
					HX_STACK_LINE(86)
					::String tmp11 = tokens->__get(i);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(86)
					bool tmp12 = (tmp11 == HX_HCSTRING("+","\x2b","\x00","\x00","\x00"));		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(86)
					bool tmp13 = !(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(86)
					bool tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(86)
					bool tmp15;		HX_STACK_VAR(tmp15,"tmp15");
					HX_STACK_LINE(86)
					if ((tmp14)){
						HX_STACK_LINE(86)
						::String tmp16 = tokens->__get(i);		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(86)
						::String tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(86)
						::String tmp18 = tmp17;		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(86)
						tmp15 = (tmp18 == HX_HCSTRING("-","\x2d","\x00","\x00","\x00"));
					}
					else{
						HX_STACK_LINE(86)
						tmp15 = true;
					}
					HX_STACK_LINE(86)
					bool tmp16 = !(tmp15);		HX_STACK_VAR(tmp16,"tmp16");
					HX_STACK_LINE(86)
					bool tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
					HX_STACK_LINE(86)
					bool tmp18;		HX_STACK_VAR(tmp18,"tmp18");
					HX_STACK_LINE(86)
					if ((tmp17)){
						HX_STACK_LINE(87)
						::String tmp19 = tokens->__get(i);		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(87)
						::String tmp20 = tmp19;		HX_STACK_VAR(tmp20,"tmp20");
						HX_STACK_LINE(87)
						::String tmp21 = tmp20;		HX_STACK_VAR(tmp21,"tmp21");
						HX_STACK_LINE(87)
						tmp18 = (tmp21 == HX_HCSTRING("*","\x2a","\x00","\x00","\x00"));
					}
					else{
						HX_STACK_LINE(86)
						tmp18 = true;
					}
					HX_STACK_LINE(86)
					bool tmp19 = !(tmp18);		HX_STACK_VAR(tmp19,"tmp19");
					HX_STACK_LINE(86)
					bool tmp20;		HX_STACK_VAR(tmp20,"tmp20");
					HX_STACK_LINE(86)
					if ((tmp19)){
						HX_STACK_LINE(87)
						::String tmp21 = tokens->__get(i);		HX_STACK_VAR(tmp21,"tmp21");
						HX_STACK_LINE(87)
						::String tmp22 = tmp21;		HX_STACK_VAR(tmp22,"tmp22");
						HX_STACK_LINE(87)
						tmp20 = (tmp22 == HX_HCSTRING("/","\x2f","\x00","\x00","\x00"));
					}
					else{
						HX_STACK_LINE(86)
						tmp20 = true;
					}
					HX_STACK_LINE(86)
					if ((tmp20)){
						HX_STACK_LINE(92)
						while((true)){
							HX_STACK_LINE(92)
							bool tmp21 = (ops->length != (int)0);		HX_STACK_VAR(tmp21,"tmp21");
							HX_STACK_LINE(92)
							bool tmp22;		HX_STACK_VAR(tmp22,"tmp22");
							HX_STACK_LINE(92)
							if ((tmp21)){
								HX_STACK_LINE(92)
								::String tmp23 = tokens->__get(i);		HX_STACK_VAR(tmp23,"tmp23");
								HX_STACK_LINE(92)
								::String tmp24 = tmp23;		HX_STACK_VAR(tmp24,"tmp24");
								HX_STACK_LINE(92)
								int tmp25 = (ops->length - (int)1);		HX_STACK_VAR(tmp25,"tmp25");
								HX_STACK_LINE(92)
								int tmp26 = tmp25;		HX_STACK_VAR(tmp26,"tmp26");
								HX_STACK_LINE(92)
								::String tmp27 = ops->__get(tmp26);		HX_STACK_VAR(tmp27,"tmp27");
								HX_STACK_LINE(92)
								::String tmp28 = tmp27;		HX_STACK_VAR(tmp28,"tmp28");
								HX_STACK_LINE(92)
								::String tmp29 = tmp24;		HX_STACK_VAR(tmp29,"tmp29");
								HX_STACK_LINE(92)
								::String tmp30 = tmp28;		HX_STACK_VAR(tmp30,"tmp30");
								HX_STACK_LINE(92)
								tmp22 = this->hasPrecedence(tmp29,tmp30);
							}
							else{
								HX_STACK_LINE(92)
								tmp22 = false;
							}
							HX_STACK_LINE(92)
							bool tmp23 = !(tmp22);		HX_STACK_VAR(tmp23,"tmp23");
							HX_STACK_LINE(92)
							if ((tmp23)){
								HX_STACK_LINE(92)
								break;
							}
							HX_STACK_LINE(93)
							::String tmp24 = ops->pop();		HX_STACK_VAR(tmp24,"tmp24");
							HX_STACK_LINE(93)
							Dynamic tmp25 = values->pop();		HX_STACK_VAR(tmp25,"tmp25");
							HX_STACK_LINE(93)
							Dynamic tmp26 = values->pop();		HX_STACK_VAR(tmp26,"tmp26");
							HX_STACK_LINE(93)
							int tmp27 = this->applyOp(tmp24,tmp25,tmp26);		HX_STACK_VAR(tmp27,"tmp27");
							HX_STACK_LINE(93)
							values->push(tmp27);
						}
						HX_STACK_LINE(96)
						::String tmp21 = tokens->__get(i);		HX_STACK_VAR(tmp21,"tmp21");
						HX_STACK_LINE(96)
						ops->push(tmp21);
					}
				}
			}
		}
		HX_STACK_LINE(98)
		(i)++;
	}
	HX_STACK_LINE(103)
	while((true)){
		HX_STACK_LINE(103)
		bool tmp = (ops->length != (int)0);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(103)
		bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(103)
		if ((tmp1)){
			HX_STACK_LINE(103)
			break;
		}
		HX_STACK_LINE(104)
		::String tmp2 = ops->pop();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(104)
		Dynamic tmp3 = values->pop();		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(104)
		Dynamic tmp4 = values->pop();		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(104)
		int tmp5 = this->applyOp(tmp2,tmp3,tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(104)
		values->push(tmp5);
	}
	HX_STACK_LINE(107)
	Dynamic tmp = values->pop();		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(107)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,evaluate,return )

bool Calculator_obj::hasPrecedence( ::String op1,::String op2){
	HX_STACK_FRAME("Calculator","hasPrecedence",0xa3c0d1b8,"Calculator.hasPrecedence","Calculator.hx",113,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(op1,"op1")
	HX_STACK_ARG(op2,"op2")
	HX_STACK_LINE(114)
	bool tmp = (op2 == HX_HCSTRING("(","\x28","\x00","\x00","\x00"));		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(114)
	bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(114)
	bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(114)
	if ((tmp1)){
		HX_STACK_LINE(114)
		tmp2 = (op2 == HX_HCSTRING(")","\x29","\x00","\x00","\x00"));
	}
	else{
		HX_STACK_LINE(114)
		tmp2 = true;
	}
	HX_STACK_LINE(114)
	if ((tmp2)){
		HX_STACK_LINE(115)
		return false;
	}
	HX_STACK_LINE(116)
	bool tmp3 = (op1 == HX_HCSTRING("*","\x2a","\x00","\x00","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(116)
	bool tmp4 = !(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(116)
	bool tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(116)
	bool tmp6;		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(116)
	if ((tmp5)){
		HX_STACK_LINE(116)
		tmp6 = (op1 == HX_HCSTRING("/","\x2f","\x00","\x00","\x00"));
	}
	else{
		HX_STACK_LINE(116)
		tmp6 = true;
	}
	HX_STACK_LINE(116)
	bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
	HX_STACK_LINE(116)
	if ((tmp6)){
		HX_STACK_LINE(116)
		bool tmp8 = (op2 == HX_HCSTRING("+","\x2b","\x00","\x00","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(116)
		bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(116)
		bool tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(116)
		bool tmp11 = !(tmp10);		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(116)
		bool tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(116)
		bool tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(116)
		if ((tmp13)){
			HX_STACK_LINE(116)
			tmp7 = (op2 == HX_HCSTRING("-","\x2d","\x00","\x00","\x00"));
		}
		else{
			HX_STACK_LINE(116)
			tmp7 = true;
		}
	}
	else{
		HX_STACK_LINE(116)
		tmp7 = false;
	}
	HX_STACK_LINE(116)
	if ((tmp7)){
		HX_STACK_LINE(117)
		return false;
	}
	else{
		HX_STACK_LINE(119)
		return true;
	}
	HX_STACK_LINE(116)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(Calculator_obj,hasPrecedence,return )

int Calculator_obj::applyOp( ::String op,int b,int a){
	HX_STACK_FRAME("Calculator","applyOp",0xadfd26e3,"Calculator.applyOp","Calculator.hx",125,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(op,"op")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(126)
	int res = (int)0;		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(127)
	::String tmp = op;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(127)
	::String _switch_1 = (tmp);
	if (  ( _switch_1==HX_HCSTRING("+","\x2b","\x00","\x00","\x00"))){
		HX_STACK_LINE(130)
		int tmp1 = (a + b);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(130)
		res = tmp1;
		HX_STACK_LINE(131)
		::String tmp2 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + a);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(131)
		::String tmp3 = (tmp2 + HX_HCSTRING(" + ","\xb5","\x6d","\x18","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(131)
		int tmp4 = b;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(131)
		::String tmp5 = (tmp3 + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(131)
		::String tmp6 = (tmp5 + HX_HCSTRING(" = ","\x63","\x7d","\x18","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(131)
		int tmp7 = res;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(131)
		::String tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(131)
		this->operations->push(tmp8);
		HX_STACK_LINE(132)
		int tmp9 = res;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(132)
		return tmp9;
	}
	else if (  ( _switch_1==HX_HCSTRING("-","\x2d","\x00","\x00","\x00"))){
		HX_STACK_LINE(134)
		int tmp1 = (a - b);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(134)
		res = tmp1;
		HX_STACK_LINE(135)
		::String tmp2 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + a);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(135)
		::String tmp3 = (tmp2 + HX_HCSTRING(" - ","\x73","\x6f","\x18","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(135)
		int tmp4 = b;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(135)
		::String tmp5 = (tmp3 + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(135)
		::String tmp6 = (tmp5 + HX_HCSTRING(" = ","\x63","\x7d","\x18","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(135)
		int tmp7 = res;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(135)
		::String tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(135)
		this->operations->push(tmp8);
		HX_STACK_LINE(136)
		int tmp9 = res;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(136)
		return tmp9;
	}
	else if (  ( _switch_1==HX_HCSTRING("*","\x2a","\x00","\x00","\x00"))){
		HX_STACK_LINE(138)
		int tmp1 = (a * b);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(138)
		res = tmp1;
		HX_STACK_LINE(139)
		::String tmp2 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + a);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(139)
		::String tmp3 = (tmp2 + HX_HCSTRING(" * ","\xd6","\x6c","\x18","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(139)
		int tmp4 = b;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(139)
		::String tmp5 = (tmp3 + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(139)
		::String tmp6 = (tmp5 + HX_HCSTRING(" = ","\x63","\x7d","\x18","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(139)
		int tmp7 = res;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(139)
		::String tmp8 = (tmp6 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(139)
		this->operations->push(tmp8);
		HX_STACK_LINE(140)
		int tmp9 = (a * b);		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(140)
		return tmp9;
	}
	else if (  ( _switch_1==HX_HCSTRING("/","\x2f","\x00","\x00","\x00"))){
		HX_STACK_LINE(142)
		bool tmp1 = (b != (int)0);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(142)
		if ((tmp1)){
			HX_STACK_LINE(143)
			Float tmp2 = (Float(a) / Float(b));		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(143)
			int tmp3 = ::Std_obj::_int(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(143)
			res = tmp3;
			HX_STACK_LINE(144)
			::String tmp4 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + a);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(144)
			::String tmp5 = (tmp4 + HX_HCSTRING(" / ","\x31","\x71","\x18","\x00"));		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(144)
			int tmp6 = b;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(144)
			::String tmp7 = (tmp5 + tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(144)
			::String tmp8 = (tmp7 + HX_HCSTRING(" = ","\x63","\x7d","\x18","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(144)
			int tmp9 = res;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(144)
			::String tmp10 = (tmp8 + tmp9);		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(144)
			this->operations->push(tmp10);
			HX_STACK_LINE(145)
			int tmp11 = res;		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(145)
			return tmp11;
		}
		HX_STACK_LINE(147)
		::String tmp2 = (HX_HCSTRING("","\x00","\x00","\x00","\x00") + a);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(147)
		::String tmp3 = (tmp2 + HX_HCSTRING(" / ","\x31","\x71","\x18","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(147)
		int tmp4 = b;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(147)
		::String tmp5 = (tmp3 + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(147)
		::String tmp6 = (tmp5 + HX_HCSTRING(" = Error","\x65","\x57","\xae","\xe0"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(147)
		this->operations->push(tmp6);
		HX_STACK_LINE(148)
		return (int)0;
	}
	HX_STACK_LINE(150)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC3(Calculator_obj,applyOp,return )

::String Calculator_obj::getBinaryValue( int x){
	HX_STACK_FRAME("Calculator","getBinaryValue",0x3adc7c86,"Calculator.getBinaryValue","Calculator.hx",153,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(154)
	int tmp = x;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(154)
	::String tmp1 = this->recursiveBinarySolution(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(154)
	::String f1 = tmp1;		HX_STACK_VAR(f1,"f1");
	HX_STACK_LINE(155)
	::String f2 = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(f2,"f2");
	HX_STACK_LINE(156)
	{
		HX_STACK_LINE(156)
		int tmp2 = f1.length;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(156)
		int tmp3 = -(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(156)
		int tmp4 = (tmp3 + (int)1);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(156)
		int _g = tmp4;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(156)
		while((true)){
			HX_STACK_LINE(156)
			bool tmp5 = (_g < (int)1);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(156)
			bool tmp6 = !(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(156)
			if ((tmp6)){
				HX_STACK_LINE(156)
				break;
			}
			HX_STACK_LINE(156)
			int tmp7 = (_g)++;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(156)
			int i = tmp7;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(157)
			int tmp8 = i;		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(157)
			int tmp9 = -(tmp8);		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(157)
			::String tmp10 = f1.charAt(tmp9);		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(157)
			hx::AddEq(f2,tmp10);
		}
	}
	HX_STACK_LINE(158)
	::String tmp2 = f2;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(158)
	return tmp2;
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,getBinaryValue,return )

::String Calculator_obj::recursiveBinarySolution( int x){
	HX_STACK_FRAME("Calculator","recursiveBinarySolution",0x47b63760,"Calculator.recursiveBinarySolution","Calculator.hx",161,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(162)
	bool tmp = (x == (int)0);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(162)
	if ((tmp)){
		HX_STACK_LINE(163)
		return HX_HCSTRING("","\x00","\x00","\x00","\x00");
	}
	HX_STACK_LINE(164)
	int tmp1 = hx::Mod(x,(int)2);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(164)
	::String tmp2 = (tmp1 + HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(164)
	Float tmp3 = (Float(x) / Float((int)2));		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(164)
	int tmp4 = ::Std_obj::_int(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(164)
	::String tmp5 = this->recursiveBinarySolution(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(164)
	::String tmp6 = (tmp2 + tmp5);		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(164)
	return tmp6;
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,recursiveBinarySolution,return )

::String Calculator_obj::getHexadecimalValue( ::String x){
	HX_STACK_FRAME("Calculator","getHexadecimalValue",0xea91b6b0,"Calculator.getHexadecimalValue","Calculator.hx",167,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(168)
	::String tmp = x;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(168)
	::String tmp1 = this->recursiveHexadecimalSolution(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(168)
	::String f = tmp1;		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(169)
	::String tmp2 = f;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(169)
	return tmp2;
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,getHexadecimalValue,return )

::String Calculator_obj::recursiveHexadecimalSolution( ::String x){
	HX_STACK_FRAME("Calculator","recursiveHexadecimalSolution",0x477bf03e,"Calculator.recursiveHexadecimalSolution","Calculator.hx",171,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(173)
	bool tmp = (x.length <= (int)4);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(173)
	if ((tmp)){
		HX_STACK_LINE(174)
		::String tmp1 = x;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(174)
		::String tmp2 = this->getHexadecimalSymbol(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(174)
		return tmp2;
	}
	HX_STACK_LINE(175)
	int tmp1 = (x.length - (int)4);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(175)
	::String tmp2 = x.substr((int)0,tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(175)
	::String tmp3 = this->recursiveHexadecimalSolution(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(176)
	int tmp4 = (x.length - (int)4);		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(176)
	::String tmp5 = x.substr(tmp4,null());		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(176)
	::String tmp6 = this->getHexadecimalSymbol(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(175)
	::String tmp7 = (tmp3 + tmp6);		HX_STACK_VAR(tmp7,"tmp7");
	HX_STACK_LINE(175)
	return tmp7;
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,recursiveHexadecimalSolution,return )

::String Calculator_obj::getHexadecimalSymbol( ::String num){
	HX_STACK_FRAME("Calculator","getHexadecimalSymbol",0xf414cf39,"Calculator.getHexadecimalSymbol","Calculator.hx",178,0xc727f2dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(num,"num")
	HX_STACK_LINE(179)
	::String tmp = num;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(179)
	::String _switch_2 = (tmp);
	if (  ( _switch_2==HX_HCSTRING("0000","\x00","\xd4","\xde","\x1f"))){
		HX_STACK_LINE(180)
		return HX_HCSTRING("0","\x30","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0","\x30","\x00","\x00","\x00"))){
		HX_STACK_LINE(181)
		return HX_HCSTRING("0","\x30","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0001","\x01","\xd4","\xde","\x1f"))){
		HX_STACK_LINE(182)
		return HX_HCSTRING("1","\x31","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1","\x31","\x00","\x00","\x00"))){
		HX_STACK_LINE(183)
		return HX_HCSTRING("1","\x31","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0010","\xdf","\xd4","\xde","\x1f"))){
		HX_STACK_LINE(184)
		return HX_HCSTRING("2","\x32","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("10","\xdf","\x2a","\x00","\x00"))){
		HX_STACK_LINE(185)
		return HX_HCSTRING("2","\x32","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0011","\xe0","\xd4","\xde","\x1f"))){
		HX_STACK_LINE(186)
		return HX_HCSTRING("3","\x33","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("11","\xe0","\x2a","\x00","\x00"))){
		HX_STACK_LINE(187)
		return HX_HCSTRING("3","\x33","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0100","\x41","\x96","\xdf","\x1f"))){
		HX_STACK_LINE(188)
		return HX_HCSTRING("4","\x34","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("100","\x71","\x58","\x25","\x00"))){
		HX_STACK_LINE(189)
		return HX_HCSTRING("4","\x34","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0101","\x42","\x96","\xdf","\x1f"))){
		HX_STACK_LINE(190)
		return HX_HCSTRING("5","\x35","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("101","\x72","\x58","\x25","\x00"))){
		HX_STACK_LINE(191)
		return HX_HCSTRING("5","\x35","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0110","\x20","\x97","\xdf","\x1f"))){
		HX_STACK_LINE(192)
		return HX_HCSTRING("6","\x36","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("110","\x50","\x59","\x25","\x00"))){
		HX_STACK_LINE(193)
		return HX_HCSTRING("6","\x36","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("0111","\x21","\x97","\xdf","\x1f"))){
		HX_STACK_LINE(194)
		return HX_HCSTRING("7","\x37","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("111","\x51","\x59","\x25","\x00"))){
		HX_STACK_LINE(195)
		return HX_HCSTRING("7","\x37","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1000","\x9f","\x0a","\x88","\x20"))){
		HX_STACK_LINE(196)
		return HX_HCSTRING("8","\x38","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1001","\xa0","\x0a","\x88","\x20"))){
		HX_STACK_LINE(197)
		return HX_HCSTRING("9","\x39","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1010","\x7e","\x0b","\x88","\x20"))){
		HX_STACK_LINE(198)
		return HX_HCSTRING("A","\x41","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1011","\x7f","\x0b","\x88","\x20"))){
		HX_STACK_LINE(199)
		return HX_HCSTRING("B","\x42","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1100","\xe0","\xcc","\x88","\x20"))){
		HX_STACK_LINE(200)
		return HX_HCSTRING("C","\x43","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1101","\xe1","\xcc","\x88","\x20"))){
		HX_STACK_LINE(201)
		return HX_HCSTRING("C","\x43","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1110","\xbf","\xcd","\x88","\x20"))){
		HX_STACK_LINE(202)
		return HX_HCSTRING("D","\x44","\x00","\x00","\x00");
	}
	else if (  ( _switch_2==HX_HCSTRING("1111","\xc0","\xcd","\x88","\x20"))){
		HX_STACK_LINE(203)
		return HX_HCSTRING("E","\x45","\x00","\x00","\x00");
	}
	HX_STACK_LINE(206)
	return HX_HCSTRING("lel","\xd3","\x4b","\x52","\x00");
}


HX_DEFINE_DYNAMIC_FUNC1(Calculator_obj,getHexadecimalSymbol,return )


Calculator_obj::Calculator_obj()
{
}

void Calculator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Calculator);
	HX_MARK_MEMBER_NAME(originalOperation,"originalOperation");
	HX_MARK_MEMBER_NAME(result,"result");
	HX_MARK_MEMBER_NAME(resultBinary,"resultBinary");
	HX_MARK_MEMBER_NAME(resultHexadecimal,"resultHexadecimal");
	HX_MARK_MEMBER_NAME(operations,"operations");
	HX_MARK_END_CLASS();
}

void Calculator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(originalOperation,"originalOperation");
	HX_VISIT_MEMBER_NAME(result,"result");
	HX_VISIT_MEMBER_NAME(resultBinary,"resultBinary");
	HX_VISIT_MEMBER_NAME(resultHexadecimal,"resultHexadecimal");
	HX_VISIT_MEMBER_NAME(operations,"operations");
}

Dynamic Calculator_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"result") ) { return result; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"applyOp") ) { return applyOp_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"operations") ) { return operations; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"printBinary") ) { return printBinary_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resultBinary") ) { return resultBinary; }
		if (HX_FIELD_EQ(inName,"setOperation") ) { return setOperation_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"hasPrecedence") ) { return hasPrecedence_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"checkIntegrity") ) { return checkIntegrity_dyn(); }
		if (HX_FIELD_EQ(inName,"getBinaryValue") ) { return getBinaryValue_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"printOperations") ) { return printOperations_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"printHexadecimal") ) { return printHexadecimal_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"originalOperation") ) { return originalOperation; }
		if (HX_FIELD_EQ(inName,"resultHexadecimal") ) { return resultHexadecimal; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getHexadecimalValue") ) { return getHexadecimalValue_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getHexadecimalSymbol") ) { return getHexadecimalSymbol_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"recursiveBinarySolution") ) { return recursiveBinarySolution_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"recursiveHexadecimalSolution") ) { return recursiveHexadecimalSolution_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Calculator_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"result") ) { result=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"operations") ) { operations=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resultBinary") ) { resultBinary=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"originalOperation") ) { originalOperation=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resultHexadecimal") ) { resultHexadecimal=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Calculator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("originalOperation","\x96","\x9d","\x14","\xfc"));
	outFields->push(HX_HCSTRING("result","\xdd","\x68","\x84","\x08"));
	outFields->push(HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03"));
	outFields->push(HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94"));
	outFields->push(HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Calculator_obj,originalOperation),HX_HCSTRING("originalOperation","\x96","\x9d","\x14","\xfc")},
	{hx::fsInt,(int)offsetof(Calculator_obj,result),HX_HCSTRING("result","\xdd","\x68","\x84","\x08")},
	{hx::fsString,(int)offsetof(Calculator_obj,resultBinary),HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03")},
	{hx::fsString,(int)offsetof(Calculator_obj,resultHexadecimal),HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(Calculator_obj,operations),HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("originalOperation","\x96","\x9d","\x14","\xfc"),
	HX_HCSTRING("result","\xdd","\x68","\x84","\x08"),
	HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03"),
	HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94"),
	HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98"),
	HX_HCSTRING("setOperation","\x25","\x44","\x90","\xc4"),
	HX_HCSTRING("checkIntegrity","\xa5","\x6e","\x1d","\x53"),
	HX_HCSTRING("print","\x2d","\x58","\x8b","\xc8"),
	HX_HCSTRING("printBinary","\x0e","\x68","\x83","\x14"),
	HX_HCSTRING("printHexadecimal","\xfe","\x8c","\xb3","\xa9"),
	HX_HCSTRING("printOperations","\xf9","\x54","\x26","\xaf"),
	HX_HCSTRING("evaluate","\x59","\x60","\x50","\x01"),
	HX_HCSTRING("hasPrecedence","\x04","\xae","\x53","\x09"),
	HX_HCSTRING("applyOp","\x2f","\x82","\x3a","\x4e"),
	HX_HCSTRING("getBinaryValue","\xba","\x62","\xca","\xb5"),
	HX_HCSTRING("recursiveBinarySolution","\xac","\xea","\xfb","\x7d"),
	HX_HCSTRING("getHexadecimalValue","\xfc","\xd3","\x10","\x94"),
	HX_HCSTRING("recursiveHexadecimalSolution","\x72","\xc9","\xcc","\x7b"),
	HX_HCSTRING("getHexadecimalSymbol","\x6d","\x54","\xcf","\x99"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Calculator_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Calculator_obj::__mClass,"__mClass");
};

#endif

hx::Class Calculator_obj::__mClass;

void Calculator_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Calculator","\x22","\x31","\x89","\xae");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Calculator_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

