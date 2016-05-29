package ;

import thx.bigint.Decimals;
import thx.bigint.DecimalImpl;

class Number{

      var value:DecimalImpl;
      var exponent:Int;// from -99 to 99
      var nickName:String;
      var error:Int;//0=No error, 1= Overflow, 2=Too much digits,3=Div between zero, 4=imaginary number
      var numerator:Int;
      var denominator:Int;
      var innerSignParenthesis:Bool;
      var outerSignParenthesis:Bool;
      
      public function new(num:String){
	     var exponentComponent:String;
	     var valueComponent:String;
      	     var hasE:Int=num.indexOf("E");
	     this.nickName="";
	     this.innerSignParenthesis=false;
	     this.outerSignParenthesis=false;
	     this.numerator=0;
	     this.denominator=0;
	     
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
	     this.error=0;

	     compact();
      }
      private function compact(){
      	      var hasPoint:Bool;
	      var sNumber:String;
	      var len:Int;
	      var hasPoint:Bool=false;
	      if(this.value.compareTo(DecimalImpl.zero)!=0){
	            	      while(this.value.compareToAbs(DecimalImpl.ten)>=0){
	      		      this.value=this.value.divide(DecimalImpl.ten);
			      this.exponent++;
		    	      }			      
	      		      while(this.value.compareToAbs(DecimalImpl.one)<0){
	      		      this.value=this.value.multiply(DecimalImpl.ten);
		      	      this.exponent--;
	      		      }
	      }
	      
	      sNumber=this.value.toString();
	      
	      if(sNumber.indexOf(".")!=-1)
		hasPoint=true;
		
		if(hasPoint)
			sNumber=reduceValueString(sNumber);
			
	      len=sNumber.length;
	      if(sNumber.indexOf("-")!=-1)
		len--;
	      if(sNumber.indexOf(".")!=-1)
		len--;
	      if(len>8){
		this.error=2;
		if(sNumber.indexOf("-")!=-1){
			if(sNumber.indexOf(".")!=-1)
				this.value=Decimals.parse(sNumber.substr(0, 10));
			else
				this.value=Decimals.parse(sNumber.substr(0, 9));
		}
		else {
		     if(sNumber.indexOf(".")!=-1)
			this.value=Decimals.parse(sNumber.substr(0, 9));     
		     else
		     this.value=Decimals.parse(sNumber.substr(0, 8));
		}
			this.error=2;
		}
		
		sNumber=this.value.toString();
		
		if(sNumber.indexOf(".")!=-1)
			hasPoint=true;
		else hasPoint=false;
		
		if(hasPoint)
			sNumber=reduceValueString(sNumber);
			
	      if(this.exponent>99 || this.exponent<-99){
	      	this.error=1;
		this.value=Decimals.parse("0");
		}
	      else {
	      	   this.value=Decimals.parse(sNumber);
	      }
      }
      
      private function reduceValueString(sNumber:String){
      	      var  hasAnyMoreZeros=true;
	      
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
	      return sNumber;
      }
            
      static public function getCopy(x:Number){
      	     var xNum:Number;
	     xNum=new Number(x.getValue()+"E"+x.getExponent());
	     return xNum;
      }
      
      public function getError(){
            return this.error;
      }
      public function setError(x:Int){
      	     this.error=x;
      }
      public function getValue(){ return this.value;}
      
      public function getExponent(){return this.exponent;}
      public function setInnerParenthesis(){this.innerSignParenthesis=true;}
      public function getInnerParenthesis(){return this.innerSignParenthesis;}
      public function setOuterParenthesis(){return this.outerSignParenthesis=true;}
      public function getOuterParenthesis(){return this.outerSignParenthesis;}
      public function resetParenthesis(){this.innerSignParenthesis=false; this.outerSignParenthesis=false;}
      
      public function resetOverflow(){
      	      if(this.error==2){
		this.error=0;
	      }
      }
      
      public function setNickName(name:String){
      	     this.nickName=name;
      }
      
      public function negate(){
      	     this.value=this.value.negate();
      }
      
      private function getNumber(spaces:Int){
      	      var decimal:DecimalImpl;
	      if(spaces>=-7 && spaces<=7)
      	        decimal=this.value.multiply(DecimalImpl.ten.pow(spaces));
	      else
		decimal=DecimalImpl.zero;
      	      return decimal;
      }
      
      public function vPrint(form:Int=0, precision:Int=0){
      	     var name:String="";
	     var expComponent:String="";
	     var valueComponent:String="";
	     if(this.error==0){
		if((this.exponent<-8 || this.exponent>7) || form==3){
				    
				    valueComponent=this.value.toString();
				    expComponent="E"+this.exponent;
		}
		else {
		     var length:Int;
		     valueComponent=this.value.multiply(DecimalImpl.ten.pow(this.exponent)).toString();
		     if(valueComponent.indexOf(".")!=-1)
			valueComponent=reduceValueString(valueComponent);

			//QUick fix to print the number in the correct format
			length=valueComponent.length;
			if(valueComponent.indexOf("-")!=-1)
			length--;
			if(valueComponent.indexOf(".")!=-1){
				length=length-2;
				if(length>8){
				valueComponent=this.value.toString();
				    expComponent="E"+this.exponent;
				}	
			}

			//print the fixed form
			if(expComponent=="" && form==1)
				valueComponent=this.value.multiply(DecimalImpl.ten.pow(this.exponent)).roundTo(precision).toString();
				/*{
				if(valueComponent.indexOf(".")==-1){
					if(precision!=0){
					valueComponent+=".";
					var i:Int=0;
					while(i<precision){
					      valueComponent+="0";
					      i++;
					      }
					}
					
				}
				else {
				var pos:Int=valueComponent.indexOf(".")+1;
				var lastPos:Int=valueComponent.length;
				if(lastPos-pos<precision){ //Add zeros
					var i:Int=0;
					while(i<precision-(lastPos-pos)){
					      valueComponent+="0";
					      i++;
					}
				}
				else if(lastPos-pos>precision){ //Delete Zeros 
				     valueComponent=valueComponent.substr(0, pos+precision);
				     if(valueComponent.length==pos)
				          valueComponent=valueComponent.substr(0, pos-1);
				}
				}
			} //end this    */
	}
		name=valueComponent+expComponent;
	}
	else{
		switch (this.error){
		     case 1:
		     name="Overflow!";
		     case 2:
		     name="Overflow!!";
		     case 3:
		     name="Math. Error Division by Zero";
		     case 4:
		     name="Imaginary number";
		}
		
	}
	     return name;
      }
      
      public function print(){
      	     if(this.nickName=="")
		return vPrint();
	     else return this.nickName;
      
      }
      
      static public function sum(x:Number, y:Number){
      	     var rNumber:Number;
	     var xDecimals:DecimalImpl, yDecimals:DecimalImpl, rDecimals:DecimalImpl;
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
	     rDecimals=xDecimals.add(yDecimals);
	     rNumber=new Number(rDecimals.toString()+"E"+maxExp );
	     rNumber.resetOverflow();
	     return rNumber;
      }

      static public function sub(x:Number, y:Number){
             var rNumber:Number;
	     var xDecimals:DecimalImpl, yDecimals:DecimalImpl;
	     var rDecimals:DecimalImpl;
	     
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
	     trace(xDecimals.toString());
	     trace(yDecimals.toString());
	     rDecimals=xDecimals.subtract(yDecimals);
	     trace(rDecimals.toString());
	     if( (rDecimals.compareTo(xDecimals)>0 && yDecimals.compareTo(DecimalImpl.zero)>0) ||
	     	(rDecimals.compareTo(xDecimals)<0 && yDecimals.compareTo(DecimalImpl.zero)<0)
	     	)
		{
			rNumber=new Number((xDecimals.toFloat()-yDecimals.toFloat())+"E"+maxExp);
		}
		else
			rNumber=new Number(rDecimals.toString()+"E"+maxExp );
	     rNumber.resetOverflow();
	     return rNumber;
      }

      static public function mul(x:Number, y:Number){
             var rNumber:Number;
	     var rDecimals:DecimalImpl;
	     rDecimals=x.getValue().multiply(y.getValue());
	     rNumber=new Number(rDecimals.toString()+"E"+(x.getExponent()+y.getExponent()));
	     rNumber.resetOverflow();
	     return rNumber;
      }

      static public function div(x:Number, y:Number){
             var rNumber:Number;
	     var rDecimals:DecimalImpl;
	     
	     if(y.getValue().compareTo(DecimalImpl.zero)==0){
		rNumber=new Number("0");
		rNumber.setError(3);
		}
	     else{
		rDecimals=x.getValue().divideWithScale(y.getValue(),8);
	     	rNumber=new Number(rDecimals.toString()+"E"+(x.getExponent()-y.getExponent()));
	     }
	     rNumber.resetOverflow();
	     
	     //sets the numerator and denominator
	     var xString:String, yString:String;
	     var xInt:Int=0, yInt:Int=0;
	     xString=x.vPrint();
	     yString=y.vPrint();
	     if(xString.indexOf(".")==-1 && xString.indexOf("E")==-1){
	     	xInt=Std.parseInt(xString);
		if(yString.indexOf(".")==-1 && yString.indexOf("E")==-1)
			yInt=Std.parseInt(yString);
		else yInt=0;
	     }
	     else yInt=0;
	     
	     rNumber.setDivision(xInt, yInt);
	     
	     return rNumber;
      }
      public function setDivision(x:Int, y:Int){
      	     this.numerator=x;
	     this.denominator=y;
      }
      public function getNumerator(){
      	     return this.numerator;
      }
      public function getDenominator(){
      	     return this.denominator;
	    }

      static public function pow(x:Number, y:Number){
             var rNumber:Number=new Number("0");
	     var yDecimal:DecimalImpl, xDecimal:DecimalImpl;
	     var rFloat:Float;
	     var needsToChangeSign:Bool=false;
	     var dfExp:Int;
	     
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));

	     dfExp=yDecimal.multiply(Decimals.fromInt(x.getExponent())).toInt();
	     
	     if(dfExp>99 || dfExp<-99){
	     		 rNumber.setError(1);
	     }
	     else{
	     
	     //  changes the sign if if
	     if(!x.getInnerParenthesis() && xDecimal.isNegative()){
	     	trace("Primer Cambio");
	     	xDecimal=xDecimal.negate();
		needsToChangeSign=true;
	     }
	     //Changes the sign again
	     if(x.getOuterParenthesis()){
		xDecimal=xDecimal.negate();
		needsToChangeSign=!needsToChangeSign;
	     }
	     
	    //Divide by zero
	    if(xDecimal.compareTo(DecimalImpl.zero)==0 && yDecimal.compareTo(DecimalImpl.zero)<=0){ //betweenZero
		rNumber.setError(3);
	    }// root of a negative number
	    else if(yDecimal.compareTo(DecimalImpl.zero)!=0 && xDecimal.isNegative() && yDecimal.compareToAbs(DecimalImpl.one)<0 &&
	    	 	(y.getDenominator()==0 || (y.getNumerator() % 2 !=0 && y.getDenominator() % 2 ==0 ))
	    	 ){
		 trace("Primer imaginary Number");
		 rNumber.setError(4);
	    }
	    else{
		if(xDecimal.isNegative()){
			xDecimal=xDecimal.negate();
			if(yDecimal.compareTo(DecimalImpl.zero)!=0 &&!(y.getDenominator()!=0 && y.getNumerator() % 2 ==0)){
				needsToChangeSign=!needsToChangeSign;
				trace("Debe de ser tratado como absoluto");
			}
		}
		if(y.getDenominator()==0)
			rFloat=Math.pow(xDecimal.toFloat(), yDecimal.toFloat());
		else{
			rFloat=Math.pow(xDecimal.toFloat(), 1/y.getDenominator());
			rFloat=Math.pow(rFloat, y.getNumerator());
		}
		if(Math.isNaN(rFloat))
			rNumber.setError(4);
		else {
		     if(needsToChangeSign)
			rNumber=new Number("-"+rFloat);
			else
			rNumber=new Number(""+rFloat);
		     rNumber.resetOverflow();
		}
	    }
	    
	    }
	     return rNumber;
      }
      static public function equal(x:Number, y:Number):Bool{
      	     var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)==0;
      }

      static public function different(x:Number, y:Number):Bool{
             var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)!=0;
      }
      static public function moreequal(x:Number, y:Number):Bool{
             var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)>=0; 
      }
      static public function more(x:Number, y:Number):Bool{
             var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)>0;
      }
      static public function lessequal(x:Number, y:Number):Bool{
      	     var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)<=0;
      }
      static public function less(x:Number, y:Number):Bool{
      	     var xDecimal:DecimalImpl;
	     var yDecimal:DecimalImpl;
	     
	     xDecimal=x.getValue().multiply(DecimalImpl.ten.pow(x.getExponent()));
	     yDecimal=y.getValue().multiply(DecimalImpl.ten.pow(y.getExponent()));
	     return xDecimal.compareTo(yDecimal)<0;
      }
}