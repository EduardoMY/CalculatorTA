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

		resultDecimal.x=40;
		resultDecimal.y=20;
		resultDecimal.border=true;
		resultDecimal.background=true;
		
		resultBinary.x=20.0;
		resultBinary.y=100.0;
		resultBinary.border=true;

		resultHexadecimal.x=20.0;
		resultHexadecimal.y=200.0;
		resultHexadecimal.border=true;
		
		operation.x=20.0;
		operation.y=500.0;
		operation.border=true;
		operation.type=TextFieldType.INPUT;

		operations.x=200.0;
		operations.y=10.0;
		operations.border=true;
		operations.multiline=true;
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
