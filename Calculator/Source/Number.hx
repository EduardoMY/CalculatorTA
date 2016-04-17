package ;

import thx.bigint.Decimals;
import thx.bigint.DecimalImpl;

class Number{
      var value:DecimalImpl;
      var exponent:Int;// from -99 to 99
      var nickName:String;
      var error:Bool;
      
      public function new(num:String){
      
	     var exponentComponent:String;
	     var valueComponent:String;
      	     var hasE:Int=num.indexOf("E");
	     nickName="";
	     if(hasE!=-1){
		valueComponent=num.substr(0, hasE);
		exponentComponent=num.substr(hasE+1);
		this.value=Decimals.parse(valueComponent);
		this.exponent=Std.parseInt(exponentComponent);
	     }
	     else {
	     	  this.value=Decimals.parse(num);
		  this.exponent=0;
	     }
	     trace(this.value.toString());
	     
	     compact();
	     
      }

      private function compact(){
      	      var hasPoint:Bool;
	      var sNumber:String;
	      var hasPoint:Bool=false, hasAnyMoreZeros=true;
	      
      	      while(this.value.compareToAbs(DecimalImpl.ten)>=0){
		this.value=this.value.divide(DecimalImpl.ten);
		this.exponent++;
	      }
	      while(this.value.compareToAbs(DecimalImpl.zero)<0){
	      	this.value=this.value.multiply(DecimalImpl.ten);
		this.exponent--;
	      }
//	      this.value.scaleTo(4);
//	      trace("The scale is"+this.value.scale);
	      
	      sNumber=this.value.toString();
	      
	      if(sNumber.indexOf(".")!=-1)
		hasPoint=true;
		
	      if(hasPoint)
	      while(hasAnyMoreZeros){
		if(sNumber.charAt(sNumber.length-1)=="0")
			sNumber=sNumber.substr(0, sNumber.length-1);
		else
			hasAnyMoreZeros=false;
		if(sNumber.charAt(sNumber.length-1)=="."){
			sNumber=sNumber.substr(0, sNumber.length-1);
			hasAnyMoreZeros=false;
		}
	      }
	      this.value=Decimals.parse(sNumber);
	      trace("EL numero es "+this.value.toString());
      }
      
      private function getNumber(spaces:Int){
      	      var decimal:DecimalImpl;
      	      decimal=this.value.multiply(DecimalImpl.ten.pow(spaces));
      	      return decimal;
      }
     
      
      public function setNickName(name:String){
      	     this.nickName=name;
      }
      
      public function print(){
      
      	     var name:String;
	     var expComponent:String="";
	     var valueComponent:String;//=this.value.toString();
	     
      	     if(this.nickName==""){
		if(this.exponent<-7 || this.exponent>7){
				    valueComponent=this.value.toString();
				    expComponent="E"+this.exponent;
		}
		else {
		     valueComponent=this.value.multiply(DecimalImpl.ten.pow(this.exponent)).toString();
		     //expComponent="E"+this.exponent;
		}
		name=valueComponent+expComponent;
		}
	     else name= this.nickName;
	     return name;
      }

      public function isOverflowed(){
            return true;
      }
      
      public function getValue(){ return this.value;}
      
      public function getExponent(){return this.exponent;}
      
      public function hasError(){this.error=true;}
      
      static public function sum(x:Number, y:Number){
      	     var rNumber:Number;
	     var xDecimals:DecimalImpl, yDecimals:DecimalImpl;
	     var maxExp:Int, dfExp:Int;
	     if(x.getExponent()>y.getExponent()){
		maxExp=x.getExponent();
		dfExp=maxExp-y.getExponent();
		xDecimals=x.getNumber(0);
		yDecimals=y.getNumber(-dfExp);
	     }
	     else {
	     	maxExp=y.getExponent();
		dfExp=maxExp-x.getExponent();
		xDecimals=x.getNumber(-dfExp);
		yDecimals=y.getNumber(0);
	     }
	     trace(xDecimals);
	     trace(yDecimals);
	     rNumber=new Number((xDecimals.add(yDecimals)).toString()+"E"+maxExp );
	     return rNumber;
      }

      static public function sub(x:Number, y:Number){
             var rNumber:Number;
	     var xDecimals:DecimalImpl, yDecimals:DecimalImpl;
	     var maxExp:Int, dfExp:Int;
	     if(x.getExponent()>y.getExponent()){
		maxExp=x.getExponent();
		dfExp=maxExp-y.getExponent();
		xDecimals=x.getNumber(0);
		yDecimals=y.getNumber(-dfExp);
	     }
	     else {
	     	maxExp=y.getExponent();
		dfExp=maxExp-x.getExponent();
		xDecimals=x.getNumber(-dfExp);
		yDecimals=y.getNumber(0);
	     }
	     trace(xDecimals);
	     trace(yDecimals);
	     rNumber=new Number((xDecimals.subtract(yDecimals)).toString()+"E"+maxExp );
	     return rNumber;
      }

      static public function mul(x:Number, y:Number){
             var rNumber:Number;
	     rNumber=new Number(x.getValue().multiply(y.getValue()).toString());
	     return rNumber;
      }

      static public function div(x:Number, y:Number){
             var rNumber:Number;
	     rNumber=new Number(x.getValue().divideWithScale(y.getValue(),7).toString());
	     return rNumber;
      }

      static public function pow(x:Number, y:Number){
             var rNumber:Number;
	     var yDecimal:DecimalImpl, xDecimal:DecimalImpl;
	     yDecimal=y.getValue();
	     xDecimal=x.getValue();
	     
	     if(yDecimal.compareToAbs(DecimalImpl.zero)<0)
		rNumber=new Number(xDecimal.square().toString());
		else
		rNumber=new Number(xDecimal.pow(yDecimal.abs().toInt()).toString());
	     if(yDecimal.isNegative())
		rNumber=div(new Number(DecimalImpl.one.toString()), rNumber);
	     return rNumber;
      }
      
      static public function copy(x:Number){
      	     
      }

      static public function max(x:Int, y:Int){
      	     if(x>y)
	     	     return x;
	     return y;
      }

      
      static public function min(x:Int, y:Int){
      	     if(x>y)
		return y;
	 return x;
      }
      
      static public function getCopy(x:Number){
      	     var xNum:Number;
	     xNum=new Number(x.getValue()+"E"+x.getExponent());
	     return xNum;
      }
}