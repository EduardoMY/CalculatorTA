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
	var aValue:TextField;
	var bValue:TextField;
	var cValue:TextField;
	var format:TextField;

	//Simple text
	var title:TextField;
	var operationTitle:TextField;
	var operationsTitle:TextField;
	var resultDecimalTitle:TextField;
	var aTitle:TextField;
	var bTitle:TextField;
	var cTitle:TextField;
	var formatTitle:TextField;

	//fonts
	var insideText:TextFormat;
	var outsideText:TextFormat;
	var outputText:TextFormat;

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
		helpImg.x=800;
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
		addChild(aTitle);
		addChild(aValue);
		addChild(bTitle);
		addChild(bValue);
		addChild(cTitle);
		addChild(cValue);
		addChild(format);
		addChild(formatTitle);
		addChild(sprite);
	}
	
	private function onButtonClick(e:Dynamic){
		operations.text=helpMessage;
	}
	
	private function init(){

		calc=new Calculator();

		insideText=new TextFormat();
		insideText.size=20;
		outsideText=new TextFormat();
		outsideText.color=0xFFFFFF;
		outsideText.size=20;
		outputText=new TextFormat();
		outputText.size=40;

		operation=new TextField();
		operations=new TextField();
		resultDecimal=new TextField();
		aValue=new TextField();
		bValue=new TextField();
		cValue=new TextField();
		format=new TextField();

		title=new TextField();
		operationTitle=new TextField();
		operationsTitle=new TextField();
		resultDecimalTitle=new TextField();
		aTitle=new TextField();
		bTitle=new TextField();
		cTitle=new TextField();
		formatTitle=new TextField();
		
		resultDecimalTitle.x=20.0;
		resultDecimalTitle.y=20.0;
		resultDecimalTitle.text="Result: ";
		resultDecimalTitle.setTextFormat(outsideText);
		resultDecimal.x=20.0;
		resultDecimal.y=50.0;
		resultDecimal.height=60.0;
		resultDecimal.width=260.0;
		resultDecimal.setTextFormat(outputText);
		resultDecimal.selectable=true;
		resultDecimal.border=true;
		resultDecimal.background=true;
		resultDecimal.backgroundColor=0x847575;

		aTitle.x=22.0;
		aTitle.y=150.0;
		aTitle.text="A: ";
		aTitle.setTextFormat(outsideText);
		aValue.x=60.0;
		aValue.y=150.0;
		aValue.height=30.0;
		aValue.width=100.0;
		aValue.setTextFormat(insideText);
		aValue.border=true;
		aValue.background=true;
		aValue.backgroundColor=0x847575;

		bTitle.x=22.0;
		bTitle.y=190.0;
		bTitle.text="B: ";
		bTitle.setTextFormat(outsideText);
		bValue.x=60.0;
		bValue.y=190.0;
		bValue.height=30.0;
		bValue.width=100.0;
		bValue.setTextFormat(insideText);
		bValue.border=true;
		bValue.background=true;
		bValue.backgroundColor=0x847575;

		cTitle.x=22.0;
		cTitle.y=230.0;
		cTitle.text="C: ";
		cTitle.setTextFormat(outsideText);
		cValue.x=60.0;
		cValue.y=230.0;
		cValue.height=30.0;
		cValue.width=100.0;
		cValue.setTextFormat(insideText);
		cValue.border=true;
		cValue.background=true;
		cValue.backgroundColor=0x847575;

		operationTitle.x=20.0;
		operationTitle.y=470.0;
		operationTitle.width=320;
		operationTitle.height=30;
		operationTitle.text="Operation: <Insert the operation here>";
		operationTitle.setTextFormat(outsideText);
		operation.x=20.0;
		operation.y=505.0;
		operation.height=30.0;
		operation.width=600.0;
		operation.setTextFormat(insideText);
		operation.border=true;
		operation.type=TextFieldType.INPUT;
		operation.background=true;

		
		formatTitle.x=260.0;
		formatTitle.y=130.0;
		formatTitle.text="Format: ";
		formatTitle.setTextFormat(outsideText);
		format.x=260.0;
		format.y=160.0;
		format.height=30.0;
		format.width=120.0;
		format.text="std";
		format.setTextFormat(insideText);
		format.border=true;
		format.background=true;
		format.backgroundColor=0x847575;
		

		operationsTitle.x=400.0;
		operationsTitle.y=5.0;
		operationsTitle.width=240.0;
		operationsTitle.text="Operations, help or errors: ";
		operationsTitle.setTextFormat(outsideText);
		operations.x=400.0;
		operations.y=30.0;
		operations.height=400.0;
		operations.width=550.0;
		operations.multiline=true;
		operations.wordWrap=true;
		operations.setTextFormat(insideText);
		operations.border=true;
		operations.background=true;

				helpMessage="Seccion de Ayuda\n"
				     +"================\n"
				     +"**NOTA: Para navegar por el menu de Help hay que utilizar las\n"
				     +" flechas Up y Down del teclado\n"
				     +"Instrucciones:\n"
				     +"*Dar click en la barra de abajo\n"
				     +"*Insertar la operacion\n"
				     +"*Presionar la tecla enter\n"
				     +"==========================\n"
				     +"Notas Generales Importantes:\n"
				     +"Acepta la funcion root(Entero, Numero)\n"
				     +"Root no se puede utilizar anidado a si mismo\n"
				     +"El elemento de Entero sera truncado\n"
				     +"Si el numero es muy grande Entero tendra el valor de 1\n"
				     +"El sistema marcara error por problemas de sintaxis.\n"
				     +"Al marcar un error el cuadro de resultados tendra cero\n"
				     +" y en este tendra el mensaje de error.\n"
				     +"El sistema acepta numeros con signo (-N y +N).\n"
				     +"No se puede utilizar mas de un signo por numero.\n"
				     +"La operacion deben de tener un signo de igualdad al terminar.\n"
				     +"Puede tener A, B o C despues de = para asignar valor.\n"
				     +"Solo aceptan numero con precision de 8 digitos.\n"
				     +"Si excede esa precision sera error de Overflow\n"
				     +"Si en alguna operacion excede esa exactitud sera truncado\n"
				     +"E va desde -99 hasta 99\n"
				     +"Division entre cero tambien es error.\n"
				     +"Raiz de Numero negativo tambien es error\n"
				     +"Puedes poner TODOS los espacios que gustes.\n"
				     +"==========================\n"
				     +"Estructura del If\n"
				     +"La sintaxis es if, [, ], and, (, ), or, then, else,\n"
				     +" pudiendo ser en mayuscula\n"
				     +"Las operaciones de igualdad son: =, <>, >, >=, <, <=\n"
				     +"No pueden ser anidados y solo puede tener un and u or\n"
				     +"Ejemplo: if[4=4]then(3=)else(4=)\n"
				     +"if[4=4 or 5=5]then(3=)else(4=)\n *Note la separacion de or con las condiciones\n"
				     +"No se pueden tener parentesis encerrando un booleano, el sistema no lo reconoce\n"
				     +"====================\n"
				     +"Instrucciones de Format\n"
				     +"Hay 4 tipos de formatos: Real, fixed, std, SN\n"
				     +"Formato real: format real\n"
				     +"Formato fix: format fix [0:8] *Solo un numero\n"
				     +"Formato Standard: format std\n"
				     +"Formato Scientific Notation: format sn";
				     
		operations.text=helpMessage;

	}

	private function onKeyUp(event:KeyboardEvent):Void{
	if(event.keyCode==Keyboard.ENTER){
		operations.scrollV=0;
		operations.text="";
		calc.setOperation(operation.text);
		for(i in calc.printOperations())
		      operations.appendText(i+"\n");
		      resultDecimal.text=calc.print()+"";
		      format.text=calc.printForm();
		      aValue.text=calc.printAValue();
		      bValue.text=calc.printBValue();
		      cValue.text=calc.printCValue();
		}
	else if(event.keyCode==Keyboard.DOWN){
	          operations.scrollV+=1;
		  }
	else if(event.keyCode==Keyboard.UP){
		operations.scrollV-=1;
	     }

	}
}
