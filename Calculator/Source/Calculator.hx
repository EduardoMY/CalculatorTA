package ;

import haxe.Int64;
import thx.Int64s;

class Calculator{

    var originalOperation: String;
    var result:Int64;
    var resultBinary:String;
    var resultHexadecimal:String;
    var operations:Array<String>;
    var maxBits:Int=41;
    var quitExecution:Bool;
    public function new(){
    	   originalOperation="0";
    }
    
    public function setOperation(newOperation:String){
    	   this.originalOperation=newOperation;
	   var tokens:Array<String>=newOperation.split("");
	   var realTokens:Array<String>=checkIntegrity(tokens);
	   switch(realTokens.pop()){
		case "0": //No error at all
		     this.operations=[];
	   	     this.result=evaluate(realTokens);
		     if(!quitExecution){
		     this.resultBinary=getBinaryValue(this.result);
	   	     this.resultHexadecimal=getHexadecimalValue(this.resultBinary);
		     }
		     else{
	  	     this.resultBinary="";
	   	     this.resultHexadecimal="";
		     quitExecution=false;
		     }
		case "1": //Error Invalid Token
		     this.operations=["Token invalid ("+realTokens.pop()+")"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "2": //Error  Missing Operation
		     this.operations=["There is a missing operation"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "3": //Error Bad combination of signs
		     this.operations=["Bad combination of signs("+realTokens[realTokens.length-2]+realTokens[realTokens.length-1]+")"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "4": //Number too big
		     this.operations=["Overflow !!!"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "5": //Single operation
		     this.operations=["Error: Cannot aply an operation to a single number"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "6":
		     this.operations=["No = at the end"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
		case "7":
		     this.operations=["Empty operation"];
		     this.result=0;
		     this.resultBinary="";
		     this.resultHexadecimal="";
	   }
    }

    public function checkIntegrity(tokens:Array<String>){
    	   //Regex ("([ ]*[-+]?[0-9]{1,12})([ ]*[+-/*][ ]*[+-]?[0-9]{1,12})*([ ]*[=]{1}[ ]*)", "g");   
	   var i:Int=0;
	   var previousSymbol:Int=0; //0=Nothing, 1=Symbol, 2=SIgn,3=Number
	   var operators:Array<String>=["-", "+", "*", "/"];
	   var values:Array<String>=[];
	   var expressionStillValid:Bool=true;
	   var status:Int=6;
	   
	   if(tokens.length==0){
		trace("emptyyyyyy");
		status=7;
		expressionStillValid=false;
	   }
	   while(i<tokens.length && expressionStillValid){
	   	trace(tokens[i]);
	   	if(tokens[i] == " "){
			     i++;
			     continue;
			     }
		if(operators.indexOf(tokens[i])!=-1){
		     if(previousSymbol==0 && (tokens[i]=="+" || tokens[i]=="-")){
		     		trace("sign star");
		     		values.push(tokens[i]);
				previousSymbol=2;
		     		}
		     else if(previousSymbol==0)
		     {
			status= 5;
			expressionStillValid=false;
		     }
		     else if(previousSymbol==1 && (tokens[i]=="+" || tokens[i]=="-")){
		     trace("weird sign");
		     	  values.push(tokens[i]);
			  previousSymbol=2;
		     }
		     else if(previousSymbol==1 ){
		     	  status=3;
			  values.push(tokens[i]);
			  expressionStillValid=false;
		     }
		     else if(previousSymbol==2){
		     	  status=3;
			  values.push(tokens[i]);
			  expressionStillValid=false;
		     }
		     else if(previousSymbol==3){
		     	values.push(tokens[i]);
			previousSymbol=1;
		     }
		     
		}
		else if(tokens[i]>="0" && tokens[i]<="9"){
		     trace(tokens[i]+"Number");
		     var posNumber:String="";
		     var realNumber:String;
		     var numberDiff:Bool;
		     if(previousSymbol==3){
			status=2;
			expressionStillValid=false;
		     }
		     else{
		     numberDiff=false;
		     while(i<tokens.length && tokens[i]>="0" && tokens[i]<="9"){
		     	if(numberDiff || tokens[i]!="0"){
				      trace("hola"+tokens[i]);
				      posNumber+=tokens[i];
				      numberDiff=true;
			}
			i++;
		     }
		     trace(posNumber+"COmpleteNumber");
			if(posNumber.length==0)
				realNumber="0";
			else realNumber=posNumber;
		     if(realNumber.length<=12){
			if(previousSymbol==2 && values.pop()=="-" && realNumber!="0")
				values.push ("-"+realNumber);
		     	else values.push(realNumber);
			previousSymbol=3;
			}
		     else {
		     	  status=4;
			  expressionStillValid=false;
		     }
		     
		     i--;
		     }
		}
		else if(tokens[i]=="="){
		     status=0;
		     expressionStillValid=false;
		}
		else { 
		     status=1;
		     values.push(tokens[i]);
		     expressionStillValid=false;
		}
	   	i++;	
	   }
	if(status==0 && previousSymbol!=3){
		status=2;
	}
	values.push(status+"");
	for(c in values)
	      trace(c+"Checar todos los digitos");
	   return values;
	   
    }
    public function print(){
    	return this.result;	
    }
    
    public function printBinary(){
      	return this.resultBinary;
    }
   
    public function printHexadecimal(){
    	return this.resultHexadecimal;
    }

    public function printOperations(){
    	   return this.operations;
	   }

	   public function evaluate(tokens:Array<String>)
    {
    
	var length:Int = tokens.length;
 	var i:Int =0;

	// Stack for numbers: 'values'
        var values:Array<Int64> = new Array<Int64>();

	// Stack for Operators: 'ops'
        var ops:Array<String> = new Array<String>();

	//Checks if the operation has to quit
	this.quitExecution=false;

	while (i <length && !this.quitExecution)
        {
	// Current token is a number, push it to stack for numbers
            if (tokens[i].length>1 || (tokens[i]>="0" && tokens[i]<="9"))
            {
                values.push(Int64s.parse(tokens[i]));		
            }
			    
            // Current token is an opening brace, push it to 'ops'
            else if (tokens[i] == "(")
                ops.push(tokens[i]);

            // Closing brace encountered, solve entire brace
            else if (tokens[i] == ")")
            {
                while (ops[ops.length-1] != "(")
                  values.push(applyOp(ops.pop(), values.pop(), values.pop()));
                ops.pop();
            }
            // Current token is an operator.
            else if (tokens[i] == "+" || tokens[i] == "-" ||
                     tokens[i] == "*" || tokens[i] == "/")
            {
                // While top of 'ops' has same or greater precedence to current
                // token, which is an operator. Apply operator on top of 'ops'
                // to top two elements in values stack
                while (ops.length!=0 && hasPrecedence(tokens[i], ops[ops.length-1]) )
                  values.push(applyOp(ops.pop(), values.pop(), values.pop()));
 
                // Push current token to 'ops'.
                ops.push(tokens[i]);
            }
	    i++;
        }
 	
        // Entire expression has been parsed at this point, apply remaining
        // ops to remaining values
        while (ops.length!=0 && !quitExecution)
            values.push(applyOp(ops.pop(), values.pop(), values.pop()));

	 //checks if there is no operation to make
	 if(this.operations.length==0){
		var a:Int64=values[0];
		operations.push('$a = $a');
	}
        // Top of 'values' contains result, return it
	return values.pop();
    }
 
    // Returns true if 'op2' has higher or same precedence as 'op1',
    // otherwise returns false.
    public function hasPrecedence(op1:String, op2:String)
    {
        if (op2 == "(" || op2 == ")")
            return false;
        if ((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-"))
            return false;
        else
            return true;
    }
    
    // A utility method to apply an operator 'op' on operands 'a' 
    // and 'b'. Return the result.
    public function applyOp(op:String, b:Int64, a:Int64)
    {
        var res:Int64=0;
	var dLimit:Int64=Int64s.parse("-999999999999");
	var uLimit:Int64=Int64s.parse("999999999999");
        switch (op)
        {
        case "+":
	    res=Int64.add(a, b);
	    if(res<=uLimit && res>=dLimit){
	    		  operations.push('$a + $b = $res');
            		  return res;
	    }
	    else {
	    	 operations.push('$a + $b = Overflow!!');
		 quitExecution=true;
		 return 0;
	    }
        case "-":
	     res=Int64.sub(a,b);
	     if(res<=uLimit && res>=dLimit){
	     	     operations.push('$a - $b = $res');
            	     return res;
	     }
	     else{
	     	     operations.push('$a - $b = Overflow');
		     quitExecution=true;
            	     return 0;
	     }
        case "*":
	     if(checksMultiplicability(a,b)){
	     	     res=Int64.mul(a,b);
		     if(res<=uLimit && res>=dLimit){
	     	     operations.push('$a * $b = $res');
            	     return a * b;
		     }
		     else {
		   	operations.push('$a * $b = Overflow');
			quitExecution=true;
                 	return 0;
		     }
	     }
	     else{
		operations.push('$a * $b = Overflow');
		quitExecution=true;
                 return 0;
	     }	     
        case "/":
            if (b != 0){
	       res=Int64.div(a ,b);
	       operations.push('$a / $b = $res');
	       return res;
	    }
		operations.push('$a / $b = Arith. Error');
		quitExecution=true;
	       return 0;
        }
        return 0;
    }
    public function checksMultiplicability(a:Int64, b:Int64){
    	   var aLength:Int;
	   var bLength:Int;
	   if(Int64.isNeg(a))
		aLength=Int64.toStr(a).length-1;
		else aLength=Int64.toStr(a).length;
	if(Int64.isNeg(b))
		bLength=Int64.toStr(b).length-1;
		else bLength=Int64.toStr(a).length;
	return aLength+bLength<=14;
    }

    public function getBinaryValue(x:Int64){
        var f1:String="";
        var f2:String="";
	if(x<=0)
		f2="0";
	else {
	f2=recursiveBinarySolution(x);
	}
		return f2;        
    }
        public function recursiveBinarySolution(x:Int64){
        if(x==0)
            return "";
        return  recursiveBinarySolution(Int64.div(x,2))+"" +Int64.mod(x,2);
    }
    public function getHexadecimalValue(x:String){
        var f:String=recursiveHexadecimalSolution(x);
        return f;
    }
     public function recursiveHexadecimalSolution(x:String){

    	   if(x.length<=4)
		return getHexadecimalSymbol(x);
	return recursiveHexadecimalSolution(x.substr(0,x.length-4)) +
	       getHexadecimalSymbol(x.substr(x.length-4));
    }

    public function getHexadecimalSymbol(num:String){
        switch(num){
	case "0000":return "0";
	case "0": return "0";
	case "0001":return "1";
	case "1": return "1";
	case "0010":return "2";
	case "10": return "2";
	case "0011":return "3";
	case "11": return "3";
	case "0100":return "4";
	case "100": return "4";
	case "0101":return "5";
	case "101": return "5";
	case "0110":return "6";
	case "110": return "6";
	case "0111":return "7";
	case "111": return "7";
	case "1000":return "8";
	case "1001":return "9";
	case "1010":return "A";
	case "1011":return "B";
	case "1100":return "C";
	case "1101":return "D";
	case "1110":return "E";
	case "1111":return "F";     
	}
	return "No";
    }
    
}