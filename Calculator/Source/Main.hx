package;

import openfl.events.KeyboardEvent;
import openfl.events.Event;
import openfl.ui.Keyboard;
import openfl.display.Sprite;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormat;
import openfl.Assets;

class Main extends Sprite {

	var operation:TextField;
	var operations:TextField;
	var resultDecimal:TextField;
	var resultBinary:TextField;
	var resultHexadecimal:TextField;

	//Simple text
	var title:TextField;
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
		addChild(operationTitle);
		addChild(operations);
		addChild(operationsTitle);
		addChild(resultDecimal);
		addChild(resultDecimalTitle);
		addChild(resultBinary);
		addChild(resultBinaryTitle);
		addChild(resultHexadecimal);
		addChild(resultHexadecimalTitle);
	}
	
	private function init(){
		calc=new Calculator();
		operation=new TextField();
		operations=new TextField();
		resultDecimal=new TextField();
		resultBinary=new TextField();
		resultHexadecimal=new TextField();

		title=new TextField();
		operationTitle=new TextField();
		operationsTitle=new TextField();
		resultDecimalTitle=new TextField();
		resultBinaryTitle=new TextField();
		resultHexadecimalTitle=new TextField();

		resultDecimalTitle.x=20.0;
		resultDecimalTitle.y=10.0;
		resultDecimalTitle.text="Result: ";
		resultDecimal.x=20.0;
		resultDecimal.y=20.0;
		resultDecimal.height=30.0;
		resultDecimal.width=200.0;
		resultDecimal.selectable=true;
		resultDecimal.border=true;
		resultDecimal.background=true;
		
		resultBinaryTitle.x=20.0;
		resultBinaryTitle.y=80.0;
		resultBinaryTitle.text="Binary: ";
		resultBinary.x=20.0;
		resultBinary.y=100.0;
		resultBinary.height=30.0;
		resultBinary.width=300.0;
		resultBinary.border=true;
		resultBinary.background=true;
		
		resultHexadecimalTitle.x=20.0;
		resultHexadecimalTitle.y=180.0;
		resultHexadecimalTitle.text="Hexadecimal: ";
		resultHexadecimal.x=20.0;
		resultHexadecimal.y=200.0;
		resultHexadecimal.height=30.0;
		resultHexadecimal.width=200.0;
		resultHexadecimal.border=true;
		resultHexadecimal.background=true;

		operationTitle.x=20.0;
		operationTitle.y=480.0;
		operationTitle.text="Operation: <Insert the operation here>";
		operation.x=20.0;
		operation.y=500.0;
		operation.height=30.0;
		operation.width=500.0;
		operation.border=true;
		operation.type=TextFieldType.INPUT;
		operation.background=true;
		
		operationsTitle.x=450.0;
		operationsTitle.y=10.0;
		operationsTitle.text="Operations or errors: ";
		operations.x=450.0;
		operations.y=20.0;
		operations.height=200.0;
		operations.width=300.0;
		operations.border=true;
		operations.multiline=true;
		operations.background=true;
	}
	
	private function onKeyUp(event:KeyboardEvent):Void{
	if(event.keyCode==Keyboard.ENTER){
		operations.text="";
		calc.setOperation(operation.text);
		for(i in calc.printOperations())
		      operations.appendText(i+"\n");
		resultDecimal.text=calc.print()+"";
		resultBinary.text=calc.printBinary();
		resultHexadecimal.text=calc.printHexadecimal();
		}
	}

}
