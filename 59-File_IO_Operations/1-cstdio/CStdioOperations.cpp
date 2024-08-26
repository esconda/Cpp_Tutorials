// Author: Burak Doğançay
#include "CStdioOperations.h"
CStdioOperations::CStdioOperations()
{
   std::cout<<"CStdio Operation Constructor is created"<<std::endl;
}

//------------------------------------------------------------------------------------
//###########OPERATION ON FILES################
void CStdioOperations::removeFunc(std::string fileName)
{
   int result = remove(fileName.c_str()); //removing file

   if(result != 0)
   {
      std::cout << "Error for deleting file : " << fileName << std::endl;
   }
   else
   {
      std::cout << "Succesfully deleted file : " << fileName << std::endl;
   }
}

void CStdioOperations::renameFunc(std::string currentPath, std::string fileName)
{
   std::string newFileName = currentPath+"/NewExampleFile.txt";
   int result = rename(fileName.c_str(), newFileName.c_str()); // renaming file

   if ( result != 0 )
   {
    std::cout << "Error for deleting file : " << fileName << std::endl;
   }
   else
   {
    std::cout << "Succesfully renamed file : " << fileName << std::endl;
   }
}

void CStdioOperations::tmpFileFunc()
{
   char buffer[256];
   FILE *pFile;
   pFile = tmpfile();

   do 
   {
      if (!fgets(buffer,256,stdin)) break; //gets line from keyboard entered data
      fputs (buffer,pFile); //write characters to file
   } while (strlen(buffer)>1);

   rewind(pFile); //sets the position indicator associated with stream to the beginning of the file.

   while (!feof(pFile)) //check end of file
   {
      if (fgets (buffer,256,pFile) == NULL) break; //get lines from file
      fputs (buffer,stdout); // write characters to stdout
   }

  fclose (pFile);
}

//------------------------------------------------------------------------------------
//###########FILE ACCESS################
void CStdioOperations::fcloseFunc(std::string fileName)
{
   FILE *pFile;
   pFile = fopen(fileName.c_str(), "wt"); //open file

   //File Control
   if (pFile == NULL) 
   {
      std::cout << "Error opening the file!\n" << std::endl;
      return;
   }

   fprintf (pFile, "fclose example"); //write text

   fclose(pFile); // Close file
}

void CStdioOperations::fflushFunc(std::string fileName)
{
   //In files open for update (i.e., open for both reading and writing), the stream shall be flushed after an output operation before performing an input operation. 
   //This can be done either by repositioning (fseek, fsetpos, rewind) or by calling explicitly fflush, like in this example:
   FILE *pFile;
   char *pBuffer;
   pFile = fopen(fileName.c_str(), "r+");

   if(pFile == NULL)
   {
      std::cout << "Error opening the file!\n" << std::endl;
      return;
   }

   fputs("Flushing Test", pFile);
   fflush(pFile); //Clear stream memory and repositioning to current position
   fgets(pBuffer, 80, pFile);
   puts(pBuffer);
   fclose(pFile);
}

void CStdioOperations::fopenFunc(std::string fileName)
{
   FILE *pFile;
   pFile = fopen(fileName.c_str(),"r+"); //Open specified file for reading mode 

   if(pFile == NULL)
   {
      std::cout << "Error opening the file!\n" << std::endl;
      return;
   }

   else
   {
      std::cout << "Succesfully opened file : " << fileName << std::endl;
   }
   fclose(pFile); // Close file
}

void CStdioOperations::freopenFunc(std::string fileName)
{
   FILE *pFile;
   char ch = 0;
   char *strWriteToFile = "Access is changed after freopen";

   //First open file in read mode and print it
   pFile = fopen(fileName.c_str(),"r"); //Open specified file for reading mode 
   
   std::cout<<"######ACCESS TYPE CHANGE OF FILE WITH FREOPEN######"<<std::endl;
   if(pFile == NULL)
   {
      std::cout << "Error opening the file!\n" << std::endl;
      return;
   }
   else
   {
      while((ch=fgetc(pFile))!=EOF)
      {
         std::cout<<ch;
      }
      std::cout<<std::endl;
      fclose(pFile);

      //then change file access type with freopen and open it with write mode
      freopen(fileName.c_str(),"w",stdout);
      fputs(strWriteToFile, stdout); // Write string to the file
      fclose(stdout); // Close the redirected stdout
   }
   std::cout<<"###################################################"<<std::endl;
}

void CStdioOperations::fprintfFunc(std::string fileName)
{

}

void CStdioOperations::fscanfFunc(std::string fileName)
{

}
void CStdioOperations::snprintfFunc(std::string fileName)
{

}

void CStdioOperations::sprintfFunc(std::string fileName)
{

}

void CStdioOperations::sscanfFunc(std::string fileName)
{

}

void CStdioOperations::vfprintfFunc(std::string fileName)
{

}

void CStdioOperations::fgetcFunc(std::string fileName)
{
   FILE *pFile;
   char ch = 0;
   char *chArray = nullptr;
   int n = 0;
   pFile = fopen(fileName.c_str(),"r");
   
   if(pFile==NULL)
   {
      perror("Error opening file");
   }
   else
   {
      do{
         chArray = (char*)realloc(chArray, (n + 1) * sizeof(char));
         ch=fgetc(pFile);
         chArray[n]=ch;
         n++;
      }while(ch != EOF);
      std::cout<<chArray<<std::endl;
      free(chArray);
   }
   fclose(pFile); // Close file
}
void CStdioOperations::fgetsFunc(std::string fileName)
{

}
void CStdioOperations::fputcFunc(std::string fileName)
{

}
void CStdioOperations::fgetposFunc(std::string fileName)
{
   FILE *pFile;
   char ch = 0;
   int n = 0;
   long long pos;
   pFile = fopen(fileName.c_str(),"r");

   if(pFile==NULL)
   {
      perror("Error opening file");
   }
   else
   {
      std::cout<<"######GET ALL CHARACTER POSITION######"<<std::endl;
      do{
         ch=fgetc(pFile);
         fgetpos (pFile,&pos);
         n++;
         std::cout<<n<<".Character of the stream : "<<ch<<std::endl;
      }while(ch != EOF);
      std::cout<<"######################################"<<std::endl;
   }
   fclose(pFile); // Close file
}