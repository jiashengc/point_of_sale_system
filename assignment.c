/*-------------------------------------------------------------------*/
/* ITS60304– Assignment #1 */
/* C Programming */
/* Student Name: <Chong Jia Sheng> <Kwan Juen Wen> */
/* Student ID: <0326800> <0322448> */
/*-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GST_ITEMS 8
#define NGST_ITEMS 6

struct Items {
	char code[6];
	char name[20];
	double price;
	int initialQuantity;
	int itemsSold;
};

void printOptions();
void purchaseItems(struct Items gst[GST_ITEMS], struct Items ngst[NGST_ITEMS]);
void editItems();
void addItems();
void deleteItems();
void showInventory(struct Items gst[GST_ITEMS], struct Items ngst[NGST_ITEMS]);
void dailyTransactions();

int main(){
	FILE *gst_file;
	FILE *ngst_file;
	struct Items gst[GST_ITEMS];
	struct Items ngst[NGST_ITEMS];
	char choice;
	//Open both files
	gst_file = fopen("gst.txt", "r");
	ngst_file = fopen("ngst.txt", "r");
	//If opening files is successfull, proceed as normal
	if((gst_file != NULL) && (ngst_file != NULL)){
		//Read from gst_file
		int i;
		for(i = 0; i < GST_ITEMS; i++){
			//Enter each item into array
			fscanf(gst_file, "%5c;%[a-zA-Z ];%lf;%d\n", 
				gst[i].code, gst[i].name, 
				&gst[i].price, &gst[i].initialQuantity
				);
			gst[i].code[5] = '\0';
			//No items have been sold yet, so set each itemsSold to 0
			gst[i].itemsSold = 0;
		}
		//Read from ngst_file
		for(i = 0; i < NGST_ITEMS; i++){
			//Enter each item into array
			fscanf(ngst_file, "%5c;%[a-zA-Z ];%lf;%d\n", 
				ngst[i].code, ngst[i].name, 
				&ngst[i].price, &ngst[i].initialQuantity
				);
			ngst[i].code[5] = '\0';
			//No items have been sold yet, so set each itemsSold to 0
			ngst[i].itemsSold = 0;
		}
		//Main operation loop
		do{
			printOptions();
			printf("Choice: ");
			scanf(" %c", &choice);
			//sleep(1); //Pause for 1 second
			if(!((choice == '2') || (choice == '3') || (choice == '4')))
				system("clear"); //Clear screen(Only works on Linux/Unix)
			switch(choice){
				case '1':	purchaseItems(gst, ngst);		break;
				case '2':	editItems();					break;
				case '3':	addItems();						break;
				case '4':	deleteItems();					break;
				case '5':	showInventory(gst, ngst);		break;
				case '6':	dailyTransactions(gst, ngst);	break;
				case '7':	puts("Goodbye.");	sleep(1);	break;
				default: 
					puts("Invalid option entered. Please try again.");
					break;
			}
			//sleep(2);
			system("clear"); //Clear screen(Only works on Linux/Unix)
		}while(choice != '7');
	}
	//If opening files has an error,
	//immediately print generic error message and exit.
	else{
		puts("Cannot open either gst.txt, or ngst.txt.");
		puts("Please close all programs using either two files try again later.");
	}
	//Close files after reading
	fclose(gst_file);
	fclose(ngst_file);
	return 0;
}

void printOptions(){
	puts("------------------------------------");
	puts("Grocery Retail"); 
	puts("------------------------------------");
	puts("1. Purchase items");
	puts("2. Edit items");
	puts("3. Add items");
	puts("4. Delete items");
	puts("5. Show inventory");
	puts("6. Show daily transaction");
	puts("7. Exit");
	puts("------------------------------------");
	puts("");
}

void purchaseItems(struct Items gst[GST_ITEMS], struct Items ngst[NGST_ITEMS]){
	char itemCode[5];
	int quantity;
	printf("Enter (Item code, Quantity), no brackets: ");
	scanf(" %s, %d", itemCode, &quantity);
	//Next line is for debugging purposes
	//printf("You entered: %s, %d\n", itemCode, quantity);
	
}

void editItems(){
	puts("This option allows user to edit items");
}

void addItems(){
	puts("This option allows user to add items");
}

void deleteItems(){
	puts("This option allows user to delete items");
}

void showInventory(struct Items gst[GST_ITEMS], struct Items ngst[NGST_ITEMS]){
	char excess;
	int i;
	//Print Taxable items
	printf("Taxable items:\n\n");
	printf("%s\t%-20s\t%-6s\t%-6s\n", 
		"Code", "Name", "Price", "Quantity");
	puts("-------------------------------------------------");
	for(i = 0; i < GST_ITEMS; i++){
		int remaining = gst[i].initialQuantity - gst[i].itemsSold;
		printf("%s\t%-20s\t%5.2f\t%d\n", 
			gst[i].code, gst[i].name, gst[i].price, remaining
			);
	}
	printf("\n\n");
	//Print Non-taxable items
	printf("Non-taxable items:\n\n");
	printf("%s\t%-20s\t%-6s\t%-6s\n", 
		"Code", "Name", "Price", "Quantity");
	puts("-------------------------------------------------");
	for(i = 0; i < NGST_ITEMS; i++){
		int remaining = gst[i].initialQuantity - gst[i].itemsSold;
		printf("%s\t%-20s\t%5.2f\t%d\n", 
			ngst[i].code, ngst[i].name, ngst[i].price, remaining
			);
	}
	printf("\nEnter a character to continue...  ");
	scanf(" %c", &excess);
}

void dailyTransactions(){
	
}
