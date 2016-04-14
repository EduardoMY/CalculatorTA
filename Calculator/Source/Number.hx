package ;

//import haxe.Int64;
//import thx.Int64s;
//import thx.bigint.BigIntImpl;
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
	     //this.value=Decimals.parse(num);
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
	     /*
	     compact();
	     */
      }
      /*
      
      private function getNumber(spaces:int){
      var number:String="";
      var int:String="";
      var deci:String="";
      
      number=this.integer+zeros[zerosAfterPoint]+this.decimals;
      if(spaces<0){
	number="."+number	
	
      }
      else {
      
      }
      return number;
      }*/
      /*
      private function compact(){
      	      var digit:String;
      	      while(this.integer>10){
		digit=(this.integer % 10)+"";
		this.integer=Std.parseInt((this.integer/10)+"");
		if(decimals!="")
			decimals=digit+decimals;
		this.exponent++;
	      }
	      while(this.integer==0 && this.decimals!=""){
	      	digit=this.decimals.charAt(0);
		this.decimals=this.decimals.substr(1);
		this.integer=Std.parseInt(digit);
		this.exponent--;
	      }
      }
      */
      public function setNickName(name:String){
      	     this.nickName=name;
      }
      
      public function print(){
      	     var name:String;
	     var expComponent:String="";
	     var valueComponent:String=this.value.toString();
	     
      	     if(this.nickName==""){
		if(this.exponent<-7 || this.exponent>7){
				    expComponent="E"+this.exponent;
		}
		else {
//			    if(this.exponent!=0){
				expComponent="E"+this.exponent;
//		      	}
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
	     //rNumber=new Number ((x.getInteger()-y.getInteger())+"");
	     rNumber=new Number((x.getValue().add(y.getValue()))+"");
	     return rNumber;
      }

      static public function sub(x:Number, y:Number){
             var rNumber:Number;
	     var 
	     rNumber=new Number(x.value.subtract(y.getValue())+"");
	     //new Number ((x.getInteger()-y.getInteger())+"");
	     return rNumber;
      }

      static public function mul(x:Number, y:Number){
             var rNumber:Number;
	     rNumber=new Number(x.getValue().multiply(y.getValue())+"");
	     //=new Number ((x.getInteger()*y.getInteger())+"");
	     return rNumber;
      }

      static public function div(x:Number, y:Number){
             var rNumber:Number;
	     rNumber=new Number(x.getValue().divideWithScale(y.getValue(),7)+"");
	     //new Number ((x.getInteger()/y.getInteger())+"");
	     return rNumber;
      }

      static public function pow(x:Number, y:Number){
             var rNumber:Number;
	     rNumber=new Number(x.getValue().pow(0)+"");
	     return rNumber;
      }
      static public function copy(x:Number){
      	     
      }
      
}