class Calculator{

    var originalOperation: String;
    
    var result:Int;
    var resultBinary:String;
    var resultHexadecimal:String;
    var operations:Array<String>;

    public function new(){
    	   originalOperation="0";
    }
    
    public function setOperation(newOperation:String){
    	   this.originalOperation=newOperation;
	   if(checkIntegrity()){
		this.operations=[];
	   	this.result=evaluate(originalOperation);
	  	 this.resultBinary=getBinaryValue(this.result);
	   	 this.resultHexadecimal=getHexadecimalValue(resultBinary);
	   }
	   else {
	   	   this.operations=["Error"];
	   	   this.result=0;
	   	   this.resultBinary="Holis";
	   	   this.resultHexadecimal="Holas";
	   }
    }

    public function checkIntegrity(){
    	   var exp:EReg=new EReg("([ ]*[-+]?[0-9]{1,12})([ ]*[+-/*][ ]*[+-]?[0-9]{1,12})*([ ]*[=]{1}[ ]*)", "g");
	   //error indexOf("="); numbers to big;
	   exp.match(this.originalOperation);
	   return exp.matched(0)==this.originalOperation;
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

    public function evaluate(expression:String)
    {
    	var tokensb:Array<String>=expression.split("");
	var tokens:Array<String>=new Array<String>();
	for(i in tokensb)
	      if(i!=" ")
	      tokens.push(i);
	      
	var length:Int = tokens.length;
 	var i:Int =0;
        // Stack for numbers: 'values'
        var values:Array<Int> = new Array<Int>();
        // Stack for Operators: 'ops'
        var ops:Array<String> = new Array<String>();
 	//Stacks the Sign of the next value
	var signs:Array<String>=new Array<String>();
        while (i <length)
        {
             // Current token is a whitespace, skip it
	     if(tokens[i]=="=")
		break;
	     else if (tokens[i]==" ")
                continue;

	// Current token is a number, push it to stack for numbers
            if ("0123456789".indexOf(tokens[i])!=-1)
            {
                var stringNumber = "";
                // There may be more than one digits in number
                while (i < length && "0123456789".indexOf(tokens[i])!=-1) {
		      stringNumber+=tokens[i];
		      i++;
		    }
                values.push(Std.parseInt(stringNumber));
		if(signs.length!=0){
			switch(signs.pop()){
			case "-":
			     values.push(values.pop()*-1);
			}
		}
		i--;
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
	    // Current token is a sign
	    else if((tokens[i]=="+" || tokens[i]=="-") &&
	    	 (i==0 || "*-+/".indexOf(tokens[i-1])!=-1 )){
		       signs.push(tokens[i]);
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
        while (ops.length!=0)
            values.push(applyOp(ops.pop(), values.pop(), values.pop()));
 
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
    public function applyOp(op:String, b:Int, a:Int)
    {
        var res:Int=0;
        switch (op)
        {
        case "+":
	     res=a + b;
	    operations.push('$a + $b = $res');
            return res;
        case "-":
	     res= a-b;
	     operations.push('$a - $b = $res');
            return res;
        case "*":
	     res= a*b;
	     operations.push('$a * $b = $res');
            return a * b;
        case "/":
            if (b != 0){
	       res=Std.int(a /b);
	       operations.push('$a / $b = $res');
	       return res;
	    }
		operations.push('$a / $b = Error');
	       return 0;
        }
        return 0;
    }

    public function getBinaryValue(x:Int){
        var f1:String="";
        var f2:String="";
	var s2:StringBuf=new StringBuf();
	if(x<=0)
		f2="0";
	else {
	f1=recursiveBinarySolution(x);
	for (i in 0...f1.length-1) 
	     s2.addChar(f1.charCodeAt(f1.length-1-i));
	f2=s2.toString();

	}
		return f2;        
    }
    
    public function recursiveBinarySolution(x:Int){
        if(x==0)
            return "";
        return x%2 + "" + recursiveBinarySolution(Std.int(x/2));
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
	case "1101":return "C";
	case "1110":return "D";
	case "1111":return "E";
	     
	}
	return "lel";
    }
}