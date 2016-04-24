package ;

class Calculator{

    var originalOperation: String;
    var result:Number;
    var a:Number;
    var aNeg:Number;
    var b:Number;
    var bNeg:Number;
    var c:Number;
    var cNeg:Number;
    var resultBinary:String="";
    var resultHexadecimal:String="";
    var operations:Array<String>;
    var quitExecution:Bool;
    
    public function new(){
    
    	   originalOperation="0";
	   a=new Number("0");
	   a.setNickName("A");
	   aNeg=new Number("0");
	   aNeg.setNickName("-A");
	   
	   b=new Number("0");
	   b.setNickName("B");
	   bNeg=new Number("0");
	   bNeg.setNickName("-B");

	   c=new Number("0");	   
	   c.setNickName("C");
	   cNeg=new Number("0");
	   cNeg.setNickName("-C");
    }
    
    public function setOperation(newOperation:String){
    	   this.originalOperation=newOperation;
	   var tokens:Array<String>=newOperation.split("");
	   var realTokens:Array<String>=checkIntegrity(tokens);
	   
	   switch(realTokens.pop()){
		case "0": //No error at all
		     this.operations=[];
		     var assign:String=realTokens.pop();
	   	     this.result=evaluate(assign, realTokens);
		     quitExecution=false;
		case "1": //Error Invalid Token
		     this.operations=["Token invalid ("+realTokens.pop()+")"];
		     this.result=new Number("0");
		case "2": //Error  Missing Operation
		     this.operations=["There is a missing operation"];
		     this.result=new Number("0");
		case "3": //Error Bad combination of signs
		     this.operations=["Bad combination of signs("+realTokens[realTokens.length-2]+realTokens[realTokens.length-1]+")"];
		     this.result=new Number("0");
		case "4": //Number too big
		     this.operations=["Overflow !!!"];
		     this.result=new Number("0");
		case "5": //Single operation
		     this.operations=["Error: Cannot aply an operation to a single number"];
		     this.result=new Number("0");
		case "6":
		     this.operations=["No = at the end"];
		     this.result=new Number("0");
		case "7":
		     this.operations=["Empty operation"];
		     this.result=new Number("0");
		case "8":
		     this.operations=["Invalid Number"];
		     this.result=new Number("0");
		case "9":
		     this.operations=["Parenthesis Mismatch"];
		     this.result=new Number("0");
	   }
    }

    public function checkIntegrity(tokens:Array<String>){
    	   //Regex ("([ ]*[-+]?[0-9]{1,12})([ ]*[+-/*][ ]*[+-]?[0-9]{1,12})*([ ]*[=]{1}[ ]*)", "g");   
	   var i:Int=0;
	   var previousSymbol:Int=0; //0=Nothing, 1=Symbol, 2=SIgn,3=Number, 4=(, 5=)
	   var operators:Array<String>=["-", "+", "*", "/", "^"];
	   var variables:Array<String>=["A", "B", "C"];
	   var values:Array<String>=[];
	   var expressionStillValid:Bool=true;
	   var status:Int=6;
	   
	   if(tokens.length==0){
		status=7;
		expressionStillValid=false;
	   }
	   while(i<tokens.length && expressionStillValid){
	   	if(tokens[i] == " "){
			     i++;
			     continue;
			     }
			     
		if(tokens[i]=="("){
			if(previousSymbol==3 || previousSymbol==5){
				expressionStillValid=false;
				status=8;
			}
			else {
			     var state:Int=0, c:Int=i;
			     state=checkParenthesis(tokens, c, "(");
			     if(state!=0){
				status=9;
				expressionStillValid=false;
			     }
			     else{
				if(previousSymbol==2 && values.pop()=="-")
						     values.push("--");
				values.push(tokens[i]);
				previousSymbol=4;
			     }
			}
		}
		else if(tokens[i]==")"){
				
				if(previousSymbol==3 || previousSymbol==5){
					var state:Int=0;
					var c:Int=i;
					state=checkParenthesis(tokens, c, ")");
					if(state!=0){
						expressionStillValid=false;
						status=9;
					}
					else { 
					     	values.push(tokens[i]);
						previousSymbol=5;
					
					}
				}
				else{
					status=8;
					expressionStillValid=false;
				}
		}
		else if(operators.indexOf(tokens[i])!=-1){
		     if((previousSymbol==0 || previousSymbol==4) && (tokens[i]=="+" || tokens[i]=="-")){
		     		values.push(tokens[i]);
				previousSymbol=2;
		     	}
		     else if(previousSymbol==0 || previousSymbol==4)
		     {
			status= 5;
			expressionStillValid=false;
		     }
		     else if(previousSymbol==1 && (tokens[i]=="+" || tokens[i]=="-")){
		     	  values.push(tokens[i]);
			  previousSymbol=2;
		     }
		     else if(previousSymbol==1 ){
		     	  status=3;
			  values.push(tokens[i]);
			  expressionStillValid=false;
		     }
		     else if(previousSymbol==3 || previousSymbol==4 || previousSymbol==5) {
		     	  previousSymbol=1;
			  values.push(tokens[i]);
		     }
		     else {
		     	  status = 3;
			  values.push(tokens[i]);
			  expressionStillValid=false;
		     }
		}
		else if(variables.indexOf(tokens[i])!=-1){//Checks if the Value is a Variable {A, B, C}
		     if(previousSymbol!=3){
				if(previousSymbol==2 && values.pop()=="-"){
					values.push("-"+tokens[i]);
				}
				else values.push(tokens[i]);
		     		previousSymbol=3;
		     }
		     else {
		     	  status=1;
		     	  expressionStillValid=false;
		     }
		}
		else if(tokens[i]=="." || (tokens[i]>="0" && tokens[i]<="9")){
		     var posNumber:String="";
		     var realNumber:String;
		     var hasPoint:Bool=false;
		     var hasNumberAfterPoint:Bool=false;
		     var hasE:Bool=false;
		     var hasNumberAfterE:Bool=false;
		     var hasMinus:Bool=false;
		     if(tokens[i]=="."){
			hasPoint=true;
			posNumber=".";
			i++;
			}
		     if(previousSymbol==3){
			status=2;
			expressionStillValid=false;
		     }
		     else{
		     	     while(i<tokens.length && (tokens[i]=="." || tokens[i]=="E" || (tokens[i]>="0" && tokens[i]<="9")) && expressionStillValid){
		     					   posNumber+=tokens[i];
		     					   if(tokens[i]=="."){
								if(hasPoint || hasE){
		     							    expressionStillValid=false;
		     							    status=8;
		     						}//if(tokens[i]==".")
		     				           else hasPoint=true;
		     					   }
		     					   else if(tokens[i]=="E"){
		     					   	if(hasE){
									expressionStillValid=false;
		     							status=8;
					       		     }
		     					     else{
								if(i<tokens.length-1 && tokens[i+1]=="-"){
									posNumber+=tokens[i+1];
									i++;
									}
							     	hasE=true;
							     }
		     					     }
							   else if(!hasE && hasPoint){
		     					   	hasNumberAfterPoint=true;
		     					   }
		     					     else if(hasE)
		     					     	     hasNumberAfterE=true;
							    i++;
						}//while
		     //Check if the
/*		     trace(posNumber);
		     trace(hasPoint);
		     trace(hasNumberAfterPoint);
		     trace(hasE);
		     trace(hasNumberAfterE); */
		     if((hasE && !hasNumberAfterE) || (hasPoint && !hasNumberAfterPoint)){
		     	      status=8;
			      expressionStillValid=false;
		     }
		     else if(expressionStillValid) {
		     	  if(previousSymbol==2){
				if(values.pop()=="-")
					values.push("-"+posNumber);
				else values.push(posNumber);
			  }
		     	  else values.push(posNumber);
		     	  previousSymbol=3;
		     }
		     i--;
		  }//big else
		     
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
		
	   }//end of big loop

	if(status==0)
		if(!(previousSymbol==3 || previousSymbol==5))
			status=2;
	
	if(status==0){
	var hasAssignation:Bool=false;
		while(i<tokens.length && !hasAssignation){
			if(variables.indexOf(tokens[i])!=-1){
			values.push(tokens[i]);
			hasAssignation=true;

			}
			i++;
		}
		if(!hasAssignation)
			values.push("");
	}

	values.push(status+"");
	return values;
    }

    public function checkParenthesis(tokens:Array<String>, i:Int, p:String){
    	   var state:Int=0, df:Int=0;
	   var sParenthesis:String="", oParenthesis:String="";
	   
	   switch(p){
	   case "(":
	   	sParenthesis=")";
		oParenthesis="(";
		df=1;
		state=-1;
		i++;
	   case ")":
	     	sParenthesis="(";
		oParenthesis=")";
		df=-1;
		state=-1;
		i--;
	   }
	   while(i>=0 && i<tokens.length && tokens[i]!="=" && state!=0){
	   	 if(tokens[i]==sParenthesis)
			state++;
		else if(tokens[i]==oParenthesis)
		     state--;
		 i=i+df;
	   }
	   return state;
    }
    
    public function print(){
    	return this.result.vPrint();	
    }

    public function printAValue(){
    	   return a.vPrint();
    }
    
    public function printBValue(){
    	   return b.vPrint();
    }
    
    public function printCValue(){
    	   return c.vPrint();
    }	

    public function printOperations(){
    	   return this.operations;
    }
	   
    public function evaluate(letter:String, tokens:Array<String>)    {
    
	var length:Int = tokens.length;
 	var i:Int =0;
	
	// Stack for numbers: 'values'
        var values:Array<Number> = new Array<Number>();

	// Stack for variables: 'variables'
	var variables:Array<String>=["A","-A", "B","-B", "C", "-C"];
	
	// Stack for Operators: 'ops'
        var ops:Array<String> = new Array<String>();

	//Checks if the operation has to quit
	this.quitExecution=false;

	while (i <length && !this.quitExecution)
        {
	trace(tokens[i]);
	// the special case of a sign affecting a number inside a Parenthesis
	   if (tokens[i]=="--")
	      ops.push(tokens[i]);
      	// Current token is a number, push it to stack for numbers
            else if (tokens[i].length>1 || variables.indexOf(tokens[i])!=-1 || (tokens[i]>="0" && tokens[i]<="9"))
            {
		if(tokens[i]=="A")
			values.push(a);
		else if(tokens[i]=="-A")
		     values.push(aNeg);
		else if(tokens[i]=="B")
		     values.push(b);
		else if(tokens[i]=="-B")
		     values.push(bNeg);
		else if(tokens[i]=="C")
		     values.push(c);
		else if(tokens[i]=="-C")
		     values.push(cNeg);
                else values.push(new Number(tokens[i]));		
            }
	     // Current token is an opening brace, push it to 'ops'
	    else if (tokens[i] == "(")
	      ops.push(tokens[i]);
            // Closing brace encountered, solve entire brace
            else if (tokens[i] == ")")
            {
		trace(ops[ops.length-1]);
                while (ops[ops.length-1] != "("){
                  values.push(applyOp(ops.pop(), values.pop(), values.pop()));
		  trace("times");
		  }
		  //CHange Parenthesis
		  values[values.length-1].setParenthesis();
		  
		  trace(ops[ops.length-1]);
                ops.pop();
		if(ops.length!=0 && ops[ops.length-1]=="--"){
			var pBefore:String, pAfter:String;
			pBefore=values[values.length-1].print();
			values[values.length-1].negate();
			pAfter=values[values.length-1].vPrint();
			operations.push('-(' + pBefore+') = '+ pAfter);
			ops.pop();
		}
            }
            // Current token is an operator.
            else if (tokens[i] == "+" || tokens[i] == "-" ||
                     tokens[i] == "*" || tokens[i] == "/" || tokens[i]=="^")
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
		var a:Number=values[0];
		if(a.getError()!=0)
			operations.push(a.vPrint());
		else
			operations.push(a.print()+' = '+ a.vPrint());
	}

	var lastValue:Number=values.pop();
	if(lastValue.getError()==0)
	switch(letter){
	case "A":
	     a=lastValue;
	     a.setNickName("A");
	     aNeg=Number.getCopy(a);
	     aNeg.negate();
	     aNeg.setNickName("-A");
	     return a;
	case "B":
	     b=lastValue;
	     b.setNickName("B");
	     bNeg=Number.getCopy(b);
	     bNeg.negate();
	     bNeg.setNickName("-B");
	     return b;
	case "C":
	     c=lastValue;
	     c.setNickName("C");
	     cNeg=Number.getCopy(c);
	     cNeg.negate();
	     cNeg.setNickName("-C");
	     return c;
	}
        // Top of 'values' contains result, return it
	return lastValue;
    }
 
    // Returns true if 'op2' has higher or same precedence as 'op1',
    // otherwise returns false.
    public function hasPrecedence(op1:String, op2:String)
    {
        if (op2 == "(" || op2 == ")")
            return false;
	else if(op1=="^")
		return false;
        else if ((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-"))
            return false;
        else
            return true;
    }
    
    // A utility method to apply an operator 'op' on operands 'a' 
    // and 'b'. Return the result.
    public function applyOp(op:String, b:Number, a:Number)
    {

        var res:Number;
	trace("It breaks here");
	trace(op);
	if(a.getError()!=0 || b.getError()!=0){
		operations.push("Overflow!!");
		this.quitExecution=true;
	}
	else{
        switch (op)
        {
        case "+":
	    res=Number.sum(a, b);
	    operations.push(a.print()+' + ' + b.print()+' = '+res.print());
	    if(res.getError()==0)
	                return res;
	    else 
		 this.quitExecution=true;
        case "-":
	     res=Number.sub(a,b);
     	     operations.push(a.print()+' - ' + b.print()+' = '+res.print());
	     if(res.getError()==0)
		return res;
	     else 
	     	 this.quitExecution=true;
        case "*":
	     res=Number.mul(a,b);
	     operations.push(a.print()+' * ' + b.print()+' = '+res.print());
	     if(res.getError()==0)
		return res;
	     else 
	     	  this.quitExecution=true;
        case "/":
	       res=Number.div(a ,b);
	       operations.push(a.print()+' / ' + b.print()+' = '+res.print());
	       if(res.getError()==0)
		return res;
	       else 
	       this.quitExecution=true;
	case "^":     
	     res=Number.pow(a,b);
	     operations.push(a.print()+' ^ ' + b.print()+' = '+res.print());
	     if(res.getError()==0)
		return res;
	     else
		this.quitExecution=true;
	     }
	     }
	 return new Number("0");
    }
    
}