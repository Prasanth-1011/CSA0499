#include <stdio.h>
struct clientData
{
	unsigned int acctNum; 
	char lastName[ 15 ]; 
	char firstName[ 10 ]; 
	double balance; 
}; 

int main( void )
{
	FILE *cfPtr;
	struct clientData client = {0, "", "", 0.0};
	
	if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL )
	{
		puts("File Could Not be Opened.");
	}
	else
	{
		printf( "%s", "Enter account number"
		        " ( 1 to 100, 0 to end input )\n? " );
		scanf( "%d", &client.acctNum );
		while ( client.acctNum != 0 )
		{
			printf( "%s", "Enter Last Name, First Name, Balance\n" );
			fscanf( stdin, "%14s%9s%lf", client.lastName,
			        client.firstName, &client.balance );
			fseek( cfPtr, ( client.acctNum - 1 ) *
			       sizeof( struct clientData ), SEEK_SET );
			fwrite( &client, sizeof( struct clientData ), 1, cfPtr );
			printf( "%s", "Enter Account Number\n" );
			scanf( "%d", &client.acctNum );
		fclose( cfPtr );
	}
}