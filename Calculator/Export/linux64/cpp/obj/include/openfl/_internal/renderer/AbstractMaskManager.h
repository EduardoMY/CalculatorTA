#ifndef INCLUDED_openfl__internal_renderer_AbstractMaskManager
#define INCLUDED_openfl__internal_renderer_AbstractMaskManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(openfl,_internal,renderer,AbstractMaskManager)
HX_DECLARE_CLASS3(openfl,_internal,renderer,RenderSession)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,geom,Matrix)
HX_DECLARE_CLASS2(openfl,geom,Rectangle)
namespace openfl{
namespace _internal{
namespace renderer{


class HXCPP_CLASS_ATTRIBUTES  AbstractMaskManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractMaskManager_obj OBJ_;
		AbstractMaskManager_obj();
		Void __construct(::openfl::_internal::renderer::RenderSession renderSession);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="openfl._internal.renderer.AbstractMaskManager")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< AbstractMaskManager_obj > __new(::openfl::_internal::renderer::RenderSession renderSession);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AbstractMaskManager_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("AbstractMaskManager","\xff","\xc4","\x8d","\x72"); }

		::openfl::_internal::renderer::RenderSession renderSession;
		virtual Void pushMask( ::openfl::display::DisplayObject mask);
		Dynamic pushMask_dyn();

		virtual Void pushRect( ::openfl::geom::Rectangle rect,::openfl::geom::Matrix transform);
		Dynamic pushRect_dyn();

		virtual Void popMask( );
		Dynamic popMask_dyn();

		virtual Void popRect( );
		Dynamic popRect_dyn();

		virtual Void saveState( );
		Dynamic saveState_dyn();

		virtual Void restoreState( );
		Dynamic restoreState_dyn();

};

} // end namespace openfl
} // end namespace _internal
} // end namespace renderer

#endif /* INCLUDED_openfl__internal_renderer_AbstractMaskManager */ 
