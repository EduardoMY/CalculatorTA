#include <hxcpp.h>

#ifndef INCLUDED_Calculator
#include <Calculator.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_KeyboardEvent
#include <openfl/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_openfl_text_TextField
#include <openfl/text/TextField.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",20,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(21)
	super::__construct();
	HX_STACK_LINE(22)
	::openfl::display::Stage tmp = this->stage;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(22)
	Dynamic tmp1 = this->onKeyUp_dyn();		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(22)
	tmp->addEventListener(HX_HCSTRING("keyUp","\xda","\xb9","\xfe","\xde"),tmp1,null(),null(),null());
	HX_STACK_LINE(24)
	this->init();
	HX_STACK_LINE(26)
	::openfl::text::TextField tmp2 = this->operation;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(26)
	this->addChild(tmp2);
	HX_STACK_LINE(27)
	::openfl::text::TextField tmp3 = this->operations;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(27)
	this->addChild(tmp3);
	HX_STACK_LINE(28)
	::openfl::text::TextField tmp4 = this->resultDecimal;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(28)
	this->addChild(tmp4);
	HX_STACK_LINE(29)
	::openfl::text::TextField tmp5 = this->resultBinary;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(29)
	this->addChild(tmp5);
	HX_STACK_LINE(30)
	::openfl::text::TextField tmp6 = this->resultHexadecimal;		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(30)
	this->addChild(tmp6);
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Void Main_obj::init( ){
{
		HX_STACK_FRAME("Main","init",0xea732345,"Main.init","Main.hx",33,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(34)
		::Calculator tmp = ::Calculator_obj::__new();		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(34)
		this->calc = tmp;
		HX_STACK_LINE(35)
		::openfl::text::TextField tmp1 = ::openfl::text::TextField_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(35)
		this->operation = tmp1;
		HX_STACK_LINE(36)
		::openfl::text::TextField tmp2 = ::openfl::text::TextField_obj::__new();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(36)
		this->operations = tmp2;
		HX_STACK_LINE(37)
		::openfl::text::TextField tmp3 = ::openfl::text::TextField_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(37)
		this->resultDecimal = tmp3;
		HX_STACK_LINE(38)
		::openfl::text::TextField tmp4 = ::openfl::text::TextField_obj::__new();		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(38)
		this->resultBinary = tmp4;
		HX_STACK_LINE(39)
		::openfl::text::TextField tmp5 = ::openfl::text::TextField_obj::__new();		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(39)
		this->resultHexadecimal = tmp5;
		HX_STACK_LINE(41)
		::openfl::text::TextField tmp6 = this->resultDecimal;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(41)
		tmp6->set_x((int)40);
		HX_STACK_LINE(42)
		::openfl::text::TextField tmp7 = this->resultDecimal;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(42)
		tmp7->set_y((int)20);
		HX_STACK_LINE(43)
		::openfl::text::TextField tmp8 = this->resultDecimal;		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(43)
		tmp8->set_border(true);
		HX_STACK_LINE(44)
		::openfl::text::TextField tmp9 = this->resultDecimal;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(44)
		tmp9->set_background(true);
		HX_STACK_LINE(46)
		::openfl::text::TextField tmp10 = this->resultBinary;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(46)
		tmp10->set_x(((Float)20.0));
		HX_STACK_LINE(47)
		::openfl::text::TextField tmp11 = this->resultBinary;		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(47)
		tmp11->set_y(((Float)100.0));
		HX_STACK_LINE(48)
		::openfl::text::TextField tmp12 = this->resultBinary;		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(48)
		tmp12->set_border(true);
		HX_STACK_LINE(50)
		::openfl::text::TextField tmp13 = this->resultHexadecimal;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(50)
		tmp13->set_x(((Float)20.0));
		HX_STACK_LINE(51)
		::openfl::text::TextField tmp14 = this->resultHexadecimal;		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(51)
		tmp14->set_y(((Float)200.0));
		HX_STACK_LINE(52)
		::openfl::text::TextField tmp15 = this->resultHexadecimal;		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(52)
		tmp15->set_border(true);
		HX_STACK_LINE(54)
		::openfl::text::TextField tmp16 = this->operation;		HX_STACK_VAR(tmp16,"tmp16");
		HX_STACK_LINE(54)
		tmp16->set_x(((Float)20.0));
		HX_STACK_LINE(55)
		::openfl::text::TextField tmp17 = this->operation;		HX_STACK_VAR(tmp17,"tmp17");
		HX_STACK_LINE(55)
		tmp17->set_y(((Float)500.0));
		HX_STACK_LINE(56)
		::openfl::text::TextField tmp18 = this->operation;		HX_STACK_VAR(tmp18,"tmp18");
		HX_STACK_LINE(56)
		tmp18->set_border(true);
		HX_STACK_LINE(57)
		::openfl::text::TextField tmp19 = this->operation;		HX_STACK_VAR(tmp19,"tmp19");
		HX_STACK_LINE(57)
		tmp19->set_type(((Dynamic)((int)1)));
		HX_STACK_LINE(59)
		::openfl::text::TextField tmp20 = this->operations;		HX_STACK_VAR(tmp20,"tmp20");
		HX_STACK_LINE(59)
		tmp20->set_x(((Float)200.0));
		HX_STACK_LINE(60)
		::openfl::text::TextField tmp21 = this->operations;		HX_STACK_VAR(tmp21,"tmp21");
		HX_STACK_LINE(60)
		tmp21->set_y(((Float)10.0));
		HX_STACK_LINE(61)
		::openfl::text::TextField tmp22 = this->operations;		HX_STACK_VAR(tmp22,"tmp22");
		HX_STACK_LINE(61)
		tmp22->set_border(true);
		HX_STACK_LINE(62)
		::openfl::text::TextField tmp23 = this->operations;		HX_STACK_VAR(tmp23,"tmp23");
		HX_STACK_LINE(62)
		tmp23->set_multiline(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::onKeyUp( ::openfl::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","onKeyUp",0xd96dbf26,"Main.onKeyUp","Main.hx",65,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(66)
		bool tmp = (event->keyCode == (int)13);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(66)
		if ((tmp)){
			HX_STACK_LINE(67)
			::openfl::text::TextField tmp1 = this->operations;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(67)
			tmp1->set_text(HX_HCSTRING("","\x00","\x00","\x00","\x00"));
			HX_STACK_LINE(68)
			::Calculator tmp2 = this->calc;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(68)
			::openfl::text::TextField tmp3 = this->operation;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(68)
			::String tmp4 = tmp3->get_text();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(68)
			tmp2->setOperation(tmp4);
			HX_STACK_LINE(69)
			{
				HX_STACK_LINE(69)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(69)
				::Calculator tmp5 = this->calc;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(69)
				Array< ::String > _g1 = tmp5->printOperations();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(69)
				while((true)){
					HX_STACK_LINE(69)
					bool tmp6 = (_g < _g1->length);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(69)
					bool tmp7 = !(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(69)
					if ((tmp7)){
						HX_STACK_LINE(69)
						break;
					}
					HX_STACK_LINE(69)
					::String tmp8 = _g1->__get(_g);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(69)
					::String i = tmp8;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(69)
					++(_g);
					HX_STACK_LINE(70)
					::openfl::text::TextField tmp9 = this->operations;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(70)
					::String tmp10 = i;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(70)
					tmp9->appendText(tmp10);
				}
			}
			HX_STACK_LINE(71)
			::openfl::text::TextField tmp5 = this->resultDecimal;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(71)
			::Calculator tmp6 = this->calc;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(71)
			int tmp7 = tmp6->print();		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(71)
			::String tmp8 = (tmp7 + HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(71)
			tmp5->set_text(tmp8);
			HX_STACK_LINE(72)
			::openfl::text::TextField tmp9 = this->resultBinary;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(72)
			::Calculator tmp10 = this->calc;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(72)
			::String tmp11 = tmp10->printBinary();		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(72)
			tmp9->set_text(tmp11);
			HX_STACK_LINE(73)
			::openfl::text::TextField tmp12 = this->resultHexadecimal;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(73)
			::Calculator tmp13 = this->calc;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(73)
			::String tmp14 = tmp13->printHexadecimal();		HX_STACK_VAR(tmp14,"tmp14");
			HX_STACK_LINE(73)
			tmp12->set_text(tmp14);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onKeyUp,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(operation,"operation");
	HX_MARK_MEMBER_NAME(operations,"operations");
	HX_MARK_MEMBER_NAME(resultDecimal,"resultDecimal");
	HX_MARK_MEMBER_NAME(resultBinary,"resultBinary");
	HX_MARK_MEMBER_NAME(resultHexadecimal,"resultHexadecimal");
	HX_MARK_MEMBER_NAME(calc,"calc");
	::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(operation,"operation");
	HX_VISIT_MEMBER_NAME(operations,"operations");
	HX_VISIT_MEMBER_NAME(resultDecimal,"resultDecimal");
	HX_VISIT_MEMBER_NAME(resultBinary,"resultBinary");
	HX_VISIT_MEMBER_NAME(resultHexadecimal,"resultHexadecimal");
	HX_VISIT_MEMBER_NAME(calc,"calc");
	::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"calc") ) { return calc; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"operation") ) { return operation; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"operations") ) { return operations; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resultBinary") ) { return resultBinary; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resultDecimal") ) { return resultDecimal; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"resultHexadecimal") ) { return resultHexadecimal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"calc") ) { calc=inValue.Cast< ::Calculator >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"operation") ) { operation=inValue.Cast< ::openfl::text::TextField >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"operations") ) { operations=inValue.Cast< ::openfl::text::TextField >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resultBinary") ) { resultBinary=inValue.Cast< ::openfl::text::TextField >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resultDecimal") ) { resultDecimal=inValue.Cast< ::openfl::text::TextField >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"resultHexadecimal") ) { resultHexadecimal=inValue.Cast< ::openfl::text::TextField >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("operation","\x27","\x84","\x40","\xa0"));
	outFields->push(HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98"));
	outFields->push(HX_HCSTRING("resultDecimal","\x34","\xf9","\x09","\x63"));
	outFields->push(HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03"));
	outFields->push(HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94"));
	outFields->push(HX_HCSTRING("calc","\x95","\x18","\xba","\x41"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::text::TextField*/ ,(int)offsetof(Main_obj,operation),HX_HCSTRING("operation","\x27","\x84","\x40","\xa0")},
	{hx::fsObject /*::openfl::text::TextField*/ ,(int)offsetof(Main_obj,operations),HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98")},
	{hx::fsObject /*::openfl::text::TextField*/ ,(int)offsetof(Main_obj,resultDecimal),HX_HCSTRING("resultDecimal","\x34","\xf9","\x09","\x63")},
	{hx::fsObject /*::openfl::text::TextField*/ ,(int)offsetof(Main_obj,resultBinary),HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03")},
	{hx::fsObject /*::openfl::text::TextField*/ ,(int)offsetof(Main_obj,resultHexadecimal),HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94")},
	{hx::fsObject /*::Calculator*/ ,(int)offsetof(Main_obj,calc),HX_HCSTRING("calc","\x95","\x18","\xba","\x41")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("operation","\x27","\x84","\x40","\xa0"),
	HX_HCSTRING("operations","\x6c","\x1e","\x33","\x98"),
	HX_HCSTRING("resultDecimal","\x34","\xf9","\x09","\x63"),
	HX_HCSTRING("resultBinary","\xbe","\x1c","\x6a","\x03"),
	HX_HCSTRING("resultHexadecimal","\x4e","\xda","\xcf","\x94"),
	HX_HCSTRING("calc","\x95","\x18","\xba","\x41"),
	HX_HCSTRING("init","\x10","\x3b","\xbb","\x45"),
	HX_HCSTRING("onKeyUp","\x3b","\x58","\x3c","\x75"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

hx::Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Main","\x59","\x64","\x2f","\x33");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Main_obj >;
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

