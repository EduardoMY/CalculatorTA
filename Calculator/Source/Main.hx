package;

import openfl.events.KeyboardEvent;
import openfl.events.Event;
import openfl.ui.Keyboard;
import openfl.display.Sprite;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.Assets;

class Main extends Sprite {

	var operation:TextField;
	var operations:TextField;
	var resultDecimal:TextField;
	var resultBinary:TextField;
	var resultHexadecimal:TextField;

	//Simple text
	var operationTitle:TextField;
	var operationsTitle:TextField;
	var resultDecimalTitle:TextField;
	var resultBinaryTitle:TextField;
	var resultHexadecimalTitle:TextField;
	
	var calc:Calculator;

	public function new () {
		super ();
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp);

		init();
		//Add the elements to the Sprite		
		addChild(operation);
		addChild(operations);
		addChild(resultDecimal);
		addChild(resultBinary);
		addChild(resultHexadecimal);
	}
	
	private function init(){
		calc=new Calculator();
		operation=new TextField();
		operations=new TextField();
		resultDecimal=new TextField();
		resultBinary=new TextField();
		resultHexadecimal=new TextField();

		resultDecimal.x=20;
		resultDecimal.y=20;
		resultDecimal.height=30.0;
		resultDecimal.width=200.0;
//		resultDecimal.autoSize=TextFieldAutoSize.LEFT;
		resultDecimal.selectable=true;
		resultDecimal.border=true;
		resultDecimal.background=true;
		
		
		resultBinary.x=20.0;
		resultBinary.y=100.0;
		resultBinary.height=30.0;
		resultBinary.width=300.0;
		resultBinary.border=true;
		resultBinary.background=true;

		resultHexadecimal.x=20.0;
		resultHexadecimal.y=200.0;
		resultHexadecimal.height=30.0;
		resultHexadecimal.width=200.0;
		resultHexadecimal.border=true;
		resultHexadecimal.background=true;
		
		operation.x=20.0;
		operation.y=500.0;
		operation.height=30.0;
		operation.width=500.0;
		operation.border=true;
		operation.type=TextFieldType.INPUT;
		operation.background=true;

		operations.x=500.0;
		operations.y=20.0;
		operations.height=400.0;
		operations.width=200.0;
		operations.border=true;
		operations.multiline=true;
		operations.background=true;
	}
	
	private function onKeyUp(event:KeyboardEvent):Void{
	if(event.keyCode==Keyboard.ENTER){
		operations.text="";
		calc.setOperation(operation.text);
		for(i in calc.printOperations())
		      operations.appendText(i);
		resultDecimal.text=calc.print()+"";
		resultBinary.text=calc.printBinary();
		resultHexadecimal.text=calc.printHexadecimal();
		}
	}

}
