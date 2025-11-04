//TODO
/*	
	replace if statements with switch ones
	show when a word has been used fully, prevent user confusion
	prevent already entered words from being entered again
	display warnings
	check if word is in word list
	fix mainMap bug where 3 characters appear at bottom
	
*/


#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

//#include "wordlist.txt"
#include "font/A.ppm"
#include "font/B.ppm"
#include "font/C.ppm"
#include "font/D.ppm"
#include "font/E.ppm"
#include "font/F.ppm"
#include "font/G.ppm"
#include "font/H.ppm"
#include "font/I.ppm"
#include "font/J.ppm"
#include "font/K.ppm"
#include "font/L.ppm"
#include "font/M.ppm"
#include "font/N.ppm"
#include "font/O.ppm"
#include "font/P.ppm"
#include "font/Q.ppm"
#include "font/R.ppm"
#include "font/S.ppm"
#include "font/T.ppm"
#include "font/U.ppm"
#include "font/V.ppm"
#include "font/W.ppm"
#include "font/X.ppm"
#include "font/Y.ppm"
#include "font/Z.ppm"
//map and system

//main jon
int mainMap[30]={
 0,0,0,0,0,
 0,0,0,0,0,
 0,0,0,0,0,
 0,0,0,0,0,
 0,0,0,0,0,
 0,0,0,0,0
};



/*
//virtual kb defenitions
int kbA = 1;
int kbB = 2;
int kbC = 3;
int kBD = 4;
int kbE = 5;
int kbF = 6;
int kbG = 7;
int kbH = 8;
int kbI = 9;
int kbJ = 10;
int kbK = 11;
int kbK

*/
//a better way to do it
int kbDef[26]={
	1,2,3,4,5,6,7,8,9,10,11,12,13,
	14,15,16,17,18,19,20,21,22,23,24,25,26

};




//virutal keyboard rows
int kbMap1[10]={
	17,23,5,18,20,25,21,9,15,16
};

int kbMap2[9]={
	1,19,4,6,7,8,10,11,12
};

int kbMap3[7]={
	26,24,3,22,2,14,13
};
	



//dump map[] array into terminal output

void dumpMap(){
	for(int i = 0; i < 30; i++){
	
		printf("%i ", mainMap[i]);
		

	printf("\n");

}

}

int tempMap[5]={
	0,0,0,0,0

};


int titleMap[6]={
	7,12,20,5,24,20,

};


int mapScale = 64;
//debugging
int verbose = 1; //debug mode (displays variables in terminal)
int globalCount;

//text
int tileScale = 8;
//game

int row = 1; //current line that is editable
int writeCount = 0; //?
int tempWrite = 0; //index for tempMap
char word[5];
char input[5];
int wordLine = 0;
//define buttons


typedef struct{
	int aB, bB, cB, dB, eB, fB, gB, hB, iB, jB,lB, kB, mB, nB, oB, pB, qB, rB, sB, tB, uB, vB, wB, xB, yB, zB, backspaceB, enterB; //button state on off
} ButtonKeys; ButtonKeys Keys;



//Buttons

void ButtonsDown(unsigned char key, int x, int y){
	
	//alpha keys
	if(key=='a') {Keys.aB=1;}
	if(key=='b') {Keys.bB=1;}
	if(key=='c') {Keys.cB=1;}
	if(key=='d') {Keys.dB=1;}
	if(key=='e') {Keys.eB=1;}
	if(key=='f') {Keys.fB=1;}
	if(key=='g') {Keys.gB=1;}
	if(key=='h') {Keys.hB=1;}
	if(key=='i') {Keys.iB=1;}
	if(key=='j') {Keys.jB=1;}
	if(key=='k') {Keys.kB=1;}
	if(key=='l') {Keys.lB=1;}
	if(key=='m') {Keys.mB=1;}
	if(key=='n') {Keys.nB=1;}
	if(key=='o') {Keys.oB=1;}
	if(key=='p') {Keys.pB=1;}
	if(key=='q') {Keys.qB=1;}
	if(key=='r') {Keys.rB=1;}
	if(key=='s') {Keys.sB=1;}
	if(key=='t') {Keys.tB=1;}
	if(key=='u') {Keys.uB=1;}
	if(key=='v') {Keys.vB=1;}
	if(key=='w') {Keys.wB=1;}
	if(key=='x') {Keys.xB=1;}
	if(key=='y') {Keys.yB=1;}
	if(key=='z') {Keys.zB=1;}

	//other keys
	if(key==13) {Keys.enterB=1;} //enter
	if(key==8) {Keys.backspaceB=1;} //backspace

	glutPostRedisplay();

}
void ButtonsUp(unsigned char key, int x, int y){
	//alpha keys
	if(key=='a') {Keys.aB=0;}
	if(key=='b') {Keys.bB=0;}
	if(key=='c') {Keys.cB=0;}
	if(key=='d') {Keys.dB=0;}
	if(key=='e') {Keys.eB=0;}
	if(key=='f') {Keys.fB=0;}
	if(key=='g') {Keys.gB=0;}
	if(key=='h') {Keys.hB=0;}
	if(key=='i') {Keys.iB=0;}
	if(key=='j') {Keys.jB=0;}
	if(key=='k') {Keys.kB=0;}
	if(key=='l') {Keys.lB=0;}
	if(key=='m') {Keys.mB=0;}
	if(key=='n') {Keys.nB=0;}
	if(key=='o') {Keys.oB=0;}
	if(key=='p') {Keys.pB=0;}
	if(key=='q') {Keys.qB=0;}
	if(key=='r') {Keys.rB=0;}
	if(key=='s') {Keys.sB=0;}
	if(key=='t') {Keys.tB=0;}
	if(key=='u') {Keys.uB=0;}
	if(key=='v') {Keys.vB=0;}
	if(key=='w') {Keys.wB=0;}
	if(key=='x') {Keys.xB=0;}
	if(key=='y') {Keys.yB=0;}
	if(key=='z') {Keys.zB=0;}


	//other keys
	if(key==13) {Keys.enterB=0;} //enter
	if(key==8) {Keys.backspaceB=0;} //backspace
	glutPostRedisplay();

}

//process input

void processInput(){
	for (int iIndex = 0; iIndex < 5; iIndex++){
		for (int wIndex = 0; wIndex < 5; wIndex++){	
			if (input[iIndex+1] == word[wIndex]){
				//kb null
				//first row				
				for (int i = 0; i < 10; i++){
					if (tempMap[iIndex] == kbMap1[i] && (tempMap[iIndex] <= 26)){
						kbMap1[i] = kbMap1[i] + 78;
					
					}	
				}

				//second row				
				for (int i = 0; i < 9; i++){
					if (tempMap[iIndex] == kbMap2[i] && (tempMap[iIndex] <= 26)){
					
						kbMap2[i] = kbMap2[i] + 78;
					}	
				}
				//third row			
				for (int i = 0; i < 7; i++){
					if (tempMap[iIndex] == kbMap3[i] && (tempMap[iIndex] <= 26)){
						kbMap3[i] = kbMap3[i] + 78;
					}	
				}
				//letter match, now check postion


				if (iIndex == wIndex){
					if (tempMap[iIndex] <= 26){
						tempMap[iIndex] = tempMap[iIndex] + 52;		
					}else{
					// assuming already yellow
						tempMap[iIndex] = tempMap[iIndex] + 26;		
					}	
				
				

					//same position, render green
				 }else{
					//different position, render yellow
					if (tempMap[iIndex] <= 26){
						tempMap[iIndex] = tempMap[iIndex] + 26;


					}
				}  
			}
		}		
	}
}	

//declare functions
void renderTexture(int[], int, int);
void drawMap(int[], int, int,int);
//void drawTemp(int[], int, int);
void render8Bit(int[], int, int);


void initializeGame(){
	int count = 0; //for counting lines
	char wordTemp[255];
	FILE *wordlist; //declare file pointer
	wordlist = fopen("wordlist.txt","r"); //open file
	//check if file exists
	if (wordlist == NULL) { //if file = null
		printf("Error opening wordlist.txt\n");
   		exit(1); 
  	}
  	printf("wordlist opened.\n");


	//select word
	wordLine = rand() % 14856 + 0; //generate random number between 1 and wordlist line count
	//wordLine = 0; //for testing
	
	for (count = 0; count <= wordLine; count++){
		fgets(wordTemp, 255, wordlist); //read lines
		
    		if (count == wordLine) {
        		strcpy(word, wordTemp);
			globalCount = count; //for testing

		}
	}

	fclose(wordlist);

}




void display(){
//clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


//bindings

	//alpha keys
	if(tempWrite < 5){
		//input and tempMap can only be added to if they are not full

	// this is completely retarded (tempwrite++ should be excuted last)
		if(Keys.aB == 1 ){tempMap[tempWrite] = 1; tempWrite++; input[tempWrite] = 'a';}
		if(Keys.bB == 1 ){tempMap[tempWrite] = 2; tempWrite++;  input[tempWrite] = 'b';}
		if(Keys.cB == 1 ){tempMap[tempWrite] = 3; tempWrite++; input[tempWrite] = 'c';}
		if(Keys.dB == 1){tempMap[tempWrite] = 4; tempWrite++; input[tempWrite] = 'd';}
		if(Keys.eB == 1){tempMap[tempWrite] = 5; tempWrite++; input[tempWrite] = 'e';}
		if(Keys.fB == 1 ){tempMap[tempWrite] = 6; tempWrite++; input[tempWrite] = 'f';}
		if(Keys.gB == 1 ){tempMap[tempWrite] = 7; tempWrite++; input[tempWrite] = 'g';}
		if(Keys.hB == 1 ){tempMap[tempWrite] = 8; tempWrite++; input[tempWrite] = 'h';}
		if(Keys.iB == 1){tempMap[tempWrite] = 9; tempWrite++; input[tempWrite] = 'i';}
		if(Keys.jB == 1){tempMap[tempWrite] = 10; tempWrite++; input[tempWrite] = 'j';}
		if(Keys.kB == 1 ){tempMap[tempWrite] = 11; tempWrite++; input[tempWrite] = 'k';}
		if(Keys.lB == 1 ){tempMap[tempWrite] = 12; tempWrite++; input[tempWrite] = 'l';}
		if(Keys.mB == 1 ){tempMap[tempWrite] = 13; tempWrite++; input[tempWrite] = 'm';}
		if(Keys.nB == 1){tempMap[tempWrite] = 14; tempWrite++; input[tempWrite] = 'n';}
		if(Keys.oB == 1){tempMap[tempWrite] = 15; tempWrite++; input[tempWrite] = 'o';}
		if(Keys.pB == 1 ){tempMap[tempWrite] = 16; tempWrite++; input[tempWrite] = 'p';}
		if(Keys.qB == 1 ){tempMap[tempWrite] = 17; tempWrite++; input[tempWrite] = 'q';}
		if(Keys.rB == 1 ){tempMap[tempWrite] = 18; tempWrite++; input[tempWrite] = 'r';}
		if(Keys.sB == 1){tempMap[tempWrite] = 19; tempWrite++; input[tempWrite] = 's';}
		if(Keys.tB == 1){tempMap[tempWrite] = 20; tempWrite++; input[tempWrite] = 't';}
		if(Keys.uB == 1){tempMap[tempWrite] = 21; tempWrite++; input[tempWrite] = 'u';}
		if(Keys.vB == 1 ){tempMap[tempWrite] = 22; tempWrite++; input[tempWrite] = 'v';}
		if(Keys.wB == 1 ){tempMap[tempWrite] = 23; tempWrite++; input[tempWrite] = 'w';}
		if(Keys.xB == 1 ){tempMap[tempWrite] = 24; tempWrite++; input[tempWrite] = 'x';}
		if(Keys.yB == 1){tempMap[tempWrite] = 25; tempWrite++; input[tempWrite] = 'y';}
		if(Keys.zB == 1){tempMap[tempWrite] = 26; tempWrite++; input[tempWrite] = 'z';}
	}
	//backspace
	if(Keys.backspaceB == 1 && tempWrite > 0){
		

		input[tempWrite] = ' ';	
		tempWrite = tempWrite - 1;
		tempMap[tempWrite] = 0;
	}

	//enter key behaviour
		if(Keys.enterB == 1 && tempWrite == 5){
		//increment row, copy tempWrite to map
			//check word	
			processInput();
	
			for (int i = 0; i < 5; i++){
				mainMap[i + (6*(row-1))] = tempMap[i];
				//memset(mainMap, tempMap[i], i + (5*i));
			}
			//reset tempMap and set index to 0
			tempMap[0] = 0;
			tempMap[1] = 0;
			tempMap[2] = 0;
			tempMap[3] = 0;
			tempMap[4] = 0;
			tempWrite = 0;
			row++;	
		}
	



	//draw Title and virtual keyboard
	tileScale = 4;
	mapScale = 36;
	//draw
	drawMap(titleMap,6,1,0);

	drawMap(kbMap1,10,1,500);
	drawMap(kbMap2,9,1,536);
	drawMap(kbMap3,7,1,572);

	//reset scaling
	tileScale = 8;
	mapScale = 64;
//draw main map
	drawMap(mainMap,5,6,50);

//draw editable line, draws on current line according to row var

	if (row == 1){
		drawMap(tempMap,5,1,50);
	}

	if (row == 2){
		drawMap(tempMap,5,1,114);
	}

	if (row == 3){
		drawMap(tempMap,5,1,178);
	}	

	if (row == 4){
		drawMap(tempMap,5,1,242);
	}

	if (row == 5){
		drawMap(tempMap,5,1,306);
	}

	if (row == 6){
		drawMap(tempMap,5,1,370);
	}



//verbosity

	if (verbose == 1){

		//clear console
		printf("\e[1;1H\e[2J");

		//print debug info
		printf("Row %i\n", row);
		dumpMap();

		/*
		//toggle row
		if(Keys.enterB == 1 ){
			if (row < 6){
				row++;
			}else{
				row = 1;
			}
		}
		*/

	//print debugging vars

		printf("Word: %s\n", word);
		printf("Input: %s\n", input);
		//printf("count: %i\n", globalCount);
		printf("Word Line: %i\n", wordLine);
		printf("Index: %i\n", tempWrite);

	}

	glutSwapBuffers();
}


void drawMap(int* map, int mapX, int mapY, int yOff){
//TODO replace map[y*mapY+x] with var 
	int x,y,xo,yo;
	int offset, index;
	for(x=0;x<mapX;x++){
		for(y=0;y<mapY;y++) {
   		//render main tiles for primary
    			if(map[y*mapY+x] <= 26 ) { 
    				glColor3f(1,1,1);
				offset = 0;
    			}
    			//yellow
    			if((map[y*mapY+x] > 26) && (map[y*mapY+x] <= 52) ) { 
    				glColor3f(1,1,0);
				offset = 26;
   			}
    			//green
    			if((map[y*mapY+x] > 52) ) { 
    				glColor3f(.2,1,0);
				offset = 52;

     			}
	//red
    			if((map[y*mapY+x] > 78) ) { 
    				glColor3f(1,.5,0);
				offset = 78;
     			}

	 		index = map[y*mapY+x] - offset;

    			//render background cell
   			xo = x*mapScale; yo = y*mapScale; 
   			yo = yo + yOff; 
   			glBegin(GL_QUADS); 
   			glVertex2i(xo +1, yo +1); 
  			glVertex2i(xo +1 ,yo+mapScale -1); 
   			glVertex2i(xo+mapScale -1,yo+mapScale -1);  
   			glVertex2i(xo+mapScale -1,yo +1); 
   			glEnd();
    			if(index==1){ render8Bit(a, xo, yo);  }
    			if(index==2){ render8Bit(b, xo, yo);  }
    			if(index==3){ render8Bit(c, xo, yo);  }
    			if(index==4){ render8Bit(d, xo, yo);  }
    			if(index==5){ render8Bit(e, xo, yo);  }
    			if(index==6){ render8Bit(f, xo, yo);  }
    			if(index==7){ render8Bit(g, xo, yo);  }
    			if(index==8){ render8Bit(h, xo, yo);  }
    			if(index==9){ render8Bit(i, xo, yo);  }
    			if(index==10){ render8Bit(j, xo, yo);  }
    			if(index==11){ render8Bit(k, xo, yo);  }
    			if(index==12){ render8Bit(l, xo, yo);  }
    			if(index==13){ render8Bit(m, xo, yo);  }
    			if(index==14){ render8Bit(n, xo, yo);  }
    			if(index==15){ render8Bit(o, xo, yo);  }
    			if(index==16){ render8Bit(p, xo, yo);  }
    			if(index==17){ render8Bit(q, xo, yo);  }
    			if(index==18){ render8Bit(r, xo, yo);  }
    			if(index==19){ render8Bit(s, xo, yo);  }
    			if(index==20){ render8Bit(t, xo, yo);  }
    			if(index==21){ render8Bit(u, xo, yo);  }
    			if(index==22){ render8Bit(v, xo, yo);  }
    			if(index==23){ render8Bit(w, xo, yo);  }
    			if(index==24){ render8Bit(x1, xo, yo);  }
    			if(index==25){ render8Bit(ay, xo, yo);  }
    			if(index==26){ render8Bit(z, xo, yo);  }
  		} 
	}
}




void renderTexture(int* texture, int xOff, int yOff){
	int x, y;
	for (y=0;y<64;y++){
		for(x=0; x<64;x++){
  			int pixel= (y*64+x)*3;
  			int red = texture[pixel +0];
  			int green = texture[pixel +1];
  			int blue = texture[pixel+2];
  			glPointSize(1); glColor3ub(red,green,blue); glBegin(GL_POINTS); glVertex2i(x+xOff,y+yOff); glEnd();
 		}
	}
}


void render8Bit(int* texture, int xOff, int yOff){
	int x, y, xo, yo;
	for (y=0;y<7;y++){
 		for(x=0; x<7;x++){
  			int pixel= (y*7+x);
  			if(texture[pixel] == 1){
         			glColor3ub(1,1,1); 
    				xo = x*tileScale; yo = y*tileScale; 
  				glBegin(GL_QUADS); 
  				glVertex2i(xOff+xo , yOff+yo ); 
				glVertex2i(xOff+xo  ,yOff+yo+tileScale ); 
   				glVertex2i(xOff+xo+tileScale ,yOff+yo+tileScale );  
   				glVertex2i(xOff+xo+tileScale, yOff+yo ); 
   				glEnd();

 			}
 		}
	}	
}


void init(){
	glClearColor(0.8,0.8,0.8,0);
 	gluOrtho2D(0,400,800,0);
}


int main(int argc, char* argv[]){
 //memset(map, 22, 12);
 
 //system("timidity test/Quake_II_-_Descent_into_Cerberon.mid"); does indeed work
	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 	glutInitWindowSize(400,600);
 	glutInitWindowPosition(200,200);
	glutCreateWindow("GLTEXT");
 	init();
	glutDisplayFunc(display);
 	glutKeyboardFunc(ButtonsDown);
 	glutKeyboardUpFunc(ButtonsUp);
 	srand(time(NULL)); //seed random number
 	initializeGame();
	glutMainLoop();
}
