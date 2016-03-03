package;

import openfl.events.KeyboardEvent;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.ui.Keyboard;
import openfl.display.Sprite;
import openfl.display.SimpleButton;
import openfl.display.Bitmap;
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

	//fonts
	var insideText:TextFormat;
	var outsideText:TextFormat;

	//Help Message
	var helpMessage:String;//Mensaje de Help
	
	var calc:Calculator;
	
	public function new () {
		super ();

		//this.mouseChildren = false;
    		//this.buttonMode = true;
			
		init();
		var bitmapData=Assets.getBitmapData("assets/help.png");
		var helpImg=new Bitmap(bitmapData);
		helpImg.width=100;
		helpImg.height=100;
		helpImg.x=600;
		helpImg.y=480;
		
		var sprite:Sprite=new Sprite();
		sprite.addChild(helpImg);
		sprite.addEventListener(MouseEvent.CLICK, onButtonClick);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKeyUp);
		
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
		addChild(sprite);
	}	
	private function onButtonClick(e:Dynamic){
		operations.text=helpMessage;
	}
	private function init(){

		calc=new Calculator();

		insideText=new TextFormat();
		insideText.size=15;
		outsideText=new TextFormat();
		outsideText.color=0xFFFFFF;
		outsideText.size=16;
		
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
		resultDecimalTitle.y=5.0;
		resultDecimalTitle.text="Result: ";
		resultDecimalTitle.setTextFormat(outsideText);
		resultDecimal.x=20.0;
		resultDecimal.y=22.0;
		resultDecimal.height=30.0;
		resultDecimal.width=200.0;
		resultDecimal.setTextFormat(insideText);
		resultDecimal.selectable=true;
		resultDecimal.border=true;
		resultDecimal.background=true;
		resultDecimal.backgroundColor=0x847575;
		resultBinaryTitle.x=20.0;
		resultBinaryTitle.y=80.0;
		resultBinaryTitle.text="Binary: ";
		resultBinaryTitle.setTextFormat(outsideText);
		resultBinary.x=20.0;
		resultBinary.y=100.0;
		resultBinary.height=30.0;
		resultBinary.width=300.0;
		resultBinary.setTextFormat(insideText);
		resultBinary.border=true;
		resultBinary.background=true;
		resultBinary.backgroundColor=0x847575;
				
		resultHexadecimalTitle.x=20.0;
		resultHexadecimalTitle.y=180.0;
		resultHexadecimalTitle.text="Hexadecimal: ";
		resultHexadecimalTitle.setTextFormat(outsideText);
		resultHexadecimal.x=20.0;
		resultHexadecimal.y=200.0;
		resultHexadecimal.height=30.0;
		resultHexadecimal.width=200.0;
		resultHexadecimal.setTextFormat(insideText);
		resultHexadecimal.border=true;
		resultHexadecimal.background=true;
		resultHexadecimal.backgroundColor=0x847575;
		
		operationTitle.x=20.0;
		operationTitle.y=470.0;
		operationTitle.width=250;
		operationTitle.height=30;
		operationTitle.text="Operation: <Insert the operation here>";
		operationTitle.setTextFormat(outsideText);
		operation.x=20.0;
		operation.y=505.0;
		operation.height=30.0;
		operation.width=500.0;
		operation.setTextFormat(insideText);
		operation.border=true;
		operation.type=TextFieldType.INPUT;
		operation.background=true;

		operationsTitle.x=400.0;
		operationsTitle.y=5.0;
		operationsTitle.width=200.0;
		operationsTitle.text="Operations, help or errors: ";
		operationsTitle.setTextFormat(outsideText);
		operations.x=400.0;
		operations.y=23.0;
		operations.height=400.0;
		operations.width=365.0;
		//operations.wordWrap=true;
		operations.setTextFormat(insideText);
		operations.border=true;
		operations.multiline=true;
		operations.background=true;

				helpMessage="Seccion de Ayuda\n"
				     +"================\n"
				     +"Instrucciones:\n"
				     +"*Dar click en la barra de abajo\n"
				     +"*Insertar la operacion\n"
				     +"*Presionar la tecla enter\n"
				     +"==========================\n"
				     +"Notas Importantes:\n"
				     +"El sistema marcara error por problemas de sintaxis.\n"
				     +"Al marcar un error el cuadro de resultados tendra cero,\n"
		   		     +"binario y Hexadecimal estaran vaciosy\n"
				     +"y este cuadro tendra el mensaje de error.\n"
				     +"El sistema acepta numeros con signo (-N y +N).\n"
				     +"No se puede utilizar mas de un signo por numero.\n"
				     +"La operacion deben de tener un signo de igualdad al terminar.\n"
				     +"Todo despues era ignorado.\n"
				     +"Solo aceptan numeros enteros y de 12 digitos.\n"
				     +"Numeros mayores seran marcados como overflow\n"
				     +"Division entre cero tambien es error.\n"
				     +"Puedes poner TODOS los espacios que gustes.\n"
				     +"Binario/hexadecimal no sirve en numeros negativos :/\n";
		operations.text=helpMessage;

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
