#ifndef INCLUDED_Calculator
#define INCLUDED_Calculator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Calculator)


class HXCPP_CLASS_ATTRIBUTES  Calculator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Calculator_obj OBJ_;
		Calculator_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="Calculator")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Calculator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Calculator_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("Calculator","\x22","\x31","\x89","\xae"); }

		::String originalOperation;
		int result;
		::String resultBinary;
		::String resultHexadecimal;
		Array< ::String > operations;
		virtual Void setOperation( ::String newOperation);
		Dynamic setOperation_dyn();

		virtual bool checkIntegrity( );
		Dynamic checkIntegrity_dyn();

		virtual int print( );
		Dynamic print_dyn();

		virtual ::String printBinary( );
		Dynamic printBinary_dyn();

		virtual ::String printHexadecimal( );
		Dynamic printHexadecimal_dyn();

		virtual Array< ::String > printOperations( );
		Dynamic printOperations_dyn();

		virtual Dynamic evaluate( ::String expression);
		Dynamic evaluate_dyn();

		virtual bool hasPrecedence( ::String op1,::String op2);
		Dynamic hasPrecedence_dyn();

		virtual int applyOp( ::String op,int b,int a);
		Dynamic applyOp_dyn();

		virtual ::String getBinaryValue( int x);
		Dynamic getBinaryValue_dyn();

		virtual ::String recursiveBinarySolution( int x);
		Dynamic recursiveBinarySolution_dyn();

		virtual ::String getHexadecimalValue( ::String x);
		Dynamic getHexadecimalValue_dyn();

		virtual ::String recursiveHexadecimalSolution( ::String x);
		Dynamic recursiveHexadecimalSolution_dyn();

		virtual ::String getHexadecimalSymbol( ::String num);
		Dynamic getHexadecimalSymbol_dyn();

};


#endif /* INCLUDED_Calculator */ 
