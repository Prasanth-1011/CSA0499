# include <stdio.h>
# include <string.h>

int main()
{
	FILE *filePointer ;
	char dataToBeWritten[50]
	    = "Operating Systems";
	filePointer = fopen("GfgTest.c", "w") ;

	if ( filePointer == NULL )
	{
		printf( "GfgTest.c File Failed to Open." ) ;
	} else {
		printf("The File is Now Opened.\n") ;

		if ( strlen ( dataToBeWritten ) > 0 )
		{
			fputs(dataToBeWritten, filePointer) ;
			fputs("\n", filePointer) ;
		}
		fclose(filePointer) ;

		printf("Data Successfully Written in File GfgTest.c\n");
		printf("The File is Now Closed.") ;
	}
	return 0;
}