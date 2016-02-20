
class Tests {
    static function main() {
        trace("Haxe is great!");
    }
}

class Test{
	var originalOperation: String;
    var compressOperation: String;
    var states: Array<Array<Bool>>;
    var result: Int;
        
    static function main(){
        var result:Int;
        result=Std.parseInt("100");
    	trace(getBinaryValue(result));
        trace(getHexadecimalValue(result));
    }
    
    static function checkIntegrity(){
     	   return true;
    }
    
    static function getBinaryValue(x:Int){
        var f1:String=recursiveBinarySolution(x);
        var f2:String="";
        for(i in -f1.length+1...1) 
    		f2+=f1.charAt(-i); 
		return f2;        
    }
    static function recursiveBinarySolution(x:Int){
        if(x==0)
            return "";
        return x%2 + "" + recursiveBinarySolution(Std.int(x/2));
    }
    
    static function getHexadecimalValue(x:Int){
        var f:String=recursiveHexadecimalSolution();
        return f;
    }
    static function recursive
    static function getHexadecimalSymbol(num:String){
        
    }
}
