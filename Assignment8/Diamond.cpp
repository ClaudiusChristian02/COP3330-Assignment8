/*************************************************************************************************************************************************************/
/*                                                                       Author and Date                                                                     */
/*

Author: Claudius Christian 
Date: 1/13/2013 

/*************************************************************************************************************************************************************/
/*                                                                       Citations                                                                           */
/*

Dr. David Gaitros provided a lot of example code for this program. Specifically I used his box example code to make my program.

/*************************************************************************************************************************************************************/
/*                                                                       Header Files                                                                        */


#include "Diamond.h"
#include <iostream>
using namespace std;

/*************************************************************************************************************************************************************/
/*                                                                       Valid Char Function                                                                 */
/*  

Author: Claudius Christian 
Date: 1/13/2013 

Description: Accepts as a parameter a constant character and checks to see if it is the range of LOWERBOUD to UPPERBOUND.  
Returns a true if so, false otherwise.                     

Parameter Description:  const char inchar - a character to be checked for validity.                                        
*/


bool validchar( const char inchar){
  if(( inchar >= 'A' && inchar <= 'Z' ) || (inchar >= 'a' && inchar <= 'z') || (inchar >= '1' && inchar <= '9') ) 
  {  
	  
	  throw out_of_range("You did not enter a valid character\n");
	  return false;

  }
  else
  {
	  return true;
  }
}

/*************************************************************************************************************************************************************/
/*                                                                       Center Function                                                                     */
/*
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Padds the front of the diamond with sufficient characters to center them within range of characters. It does this by dividing the padding size
by two to show the number of characters to the left and right of the diamond.                          
                                                             
Parameter Description: const int s - Size of the diamond.         
To be checked for validity.  
*/                                 

void center(const int s, const int q = 1)
{
  int padding = (PADDINGSIZE) / 2; 
     for (int i = 1; i < padding - q; i++)
        cout << ' ';
}
/*************************************************************************************************************************************************************/
/*                                                                       Diamond Function                                                                    */
/*
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Constructor for the Class Diamond. Creates the object for the class Diamond.  Assigns the initial values of size, border, and fill.                                 

Parameter Description: const int Diamondsize - size of the diamond, must be between 1 and 39, const char borderchar - must be a character between ! and ~, 
const char fillchar - must be a character between ! and ~. 
*/

Diamond::Diamond (const int diamondsize, const char borderchar, const char fillchar)
{ 
	try 
	{
			SetSize(diamondsize);
	}
	catch (out_of_range oor)
	{
		cout << "In Initialization" << endl;
		cout << oor.what();

		if( diamondsize < 1)
		{
		SetSize(1);
		}

		else if( diamondsize > 39 )
		{
		SetSize(39);
		}
	}

	try 
	{
			SetBorder(borderchar);
	}
	catch (out_of_range oor)
	{
		cout << oor.what();
		SetBorder(DEFAULTBORDER);
	}
	
	try 
	{
			SetFill(fillchar);
	}
	catch (out_of_range oor)
	{
		cout << oor.what();
		SetFill(DEFAULTFILL);
	}	  
}

Diamond::Diamond()
{
  size = 1;
  SetBorder('#');
  SetFill('*');
}

/*************************************************************************************************************************************************************/
/*                                                                       Draw Function                                                                       */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Draw the diamond to standard output. If the diamond is of size 1 or 2, print them out seperately. The other diamonds shall be drawn in this 
manner, Draw the top of the diamond, draw the center rows, and draw the bottom of the diamond.                                                
                                                              
Parameter Description:  None                                  
*/

  void Diamond::Draw()
{

  // ***********************************************
  // * Draw Special Diamond Case of Size One and Two
  // ***********************************************
  cout << endl; 
  if(size == SIZE1)
    { center(size, 0); 
      cout << border << endl;
      return;
    }
  if(size == SIZE2)
    {
      center(size, 0);   cout << border << endl;
      center(size, 1);   cout << border << ' ' <<  border << endl;
	  center(size, 0);   cout << border << endl;
      return;
    }

  // ***********************************************
  // * Draw the top of the Diamond
  // ***********************************************

     // The next two lines draw the top two rows of the diamond
     center(size, 0);   cout << border << endl;
     center(size, 1);   cout << border << ' ' << border << endl;

   for (int i = 1; i < size; i++)
   {
	   center(size, 1 + i);  
	   cout << border;
	   for (int w = size - i; w < size; w++)
	   {
		   cout << " " << fill;
	   }
	   cout << " " << border;
    cout << endl;
   }
  

  // ***********************************************
  // * Draw the bottom of the diamond
  // ***********************************************

 for (int i = size; i > 0; i--)
   {
	   center(size, 1 + i);  
	   cout << border;
	   for (int w = size + i; w > size; w--)
	   {
		   cout << " " << fill;
	   }
	   cout << " " << border;
    cout << endl;
   }
    
    // The next two lines draw the bottom two rows of the diamond
	center(size, 1);   cout << border << ' ' << border << endl;
	center(size, 0);   cout << border << endl;
 }

/*************************************************************************************************************************************************************/
/*                                                                       Shrink Function                                                                     */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Reduce the size of the diamond by 1 if it is not size 1 already.                                              
                                                              
Parameter Description:  None                                  
*/                                     

  void Diamond::Shrink()
{
	try
	{
		SetSize( -- size );
	}
	catch (out_of_range oor)
	{
		cout << "In shrink " << endl;
		cout<<oor.what();
		SetSize(1);
	}
}

/*************************************************************************************************************************************************************/
/*                                                                       Grow Function                                                                       */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Increase the size of the diamond by 1 if it is not size MAXIMUMSIZE already.                                    
                                                               
Parameter Description:  None                                  
*/ 

  void Diamond::Grow()
{
		try
	{
		SetSize( ++size );
	}
	catch (out_of_range oor)
	{
		cout << "In grow " << endl;
		cout<<oor.what();
		SetSize(39);
	}
}

/*************************************************************************************************************************************************************/
/*                                                                       Get Size Function                                                                   */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Return the size of the diamond.                     
                                                               
Parameter Description:  None                                  
*/

  int Diamond::GetSize()
{
  return size;
}

 /*************************************************************************************************************************************************************/
/*                                                                       Set Size Function                                                                   */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Return the size of the diamond.                     
                                                               
Parameter Description:  None                                  
*/

  void Diamond::SetSize( const int sizeInt )
{
	if( sizeInt > 39 )
	{
		char c[10];
		string str;
		str = "Invalid size. Size set to 39. Size entered was: ";
		sprintf(c, "%d\n", sizeInt);
		str.append(c);
		throw out_of_range(str);
	}

	else if( sizeInt < 1 )
	{
		char c[10];
		string str;
		str = "Invalid size. Size set to 1. Size entered was: ";
		sprintf(c, "%d\n", sizeInt);
		str.append(c);
		throw out_of_range(str);
	}

	else
	{
		size = sizeInt;
	}
}
  
/*************************************************************************************************************************************************************/
/*                                                                       Perimeter Function                                                                  */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Return the permiter of the diamond by multiplying the size by 4.                                             
                                                              
Parameter Description:  None                                  
*/

  int Diamond::Perimeter()
{
  return size * 4;
}

/*************************************************************************************************************************************************************/
/*                                                                       Get Area Function                                                                   */
/* 

Author: Claudius Christian 
Date: 1/13/2013 

Description: Return the area of the diamond by multiplying the size by itself.                                            
                                                              
Parameter Description:  None                                  
*/

  double Diamond::Area()
{
  return size * size;
}

/*************************************************************************************************************************************************************/
/*                                                                       Set Border Function                                                                 */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Set the border character. Check to see if it is a valid character otherwise set to the default to # if not.                                           

Parameter Description:  const char borderchar - border character.                                                                                     
*/

  void Diamond::SetBorder(const char borderchar)
{
   if(validchar(borderchar))
       border = borderchar;
  else border = DEFAULTBORDER;
}

/*************************************************************************************************************************************************************/
/*                                                                       Set Fill Function                                                                   */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Set the Fill character. Check to see if it is a valid character otherwise set to the default to if not.                                               

Parameter Description:  const char fillchar - fill character.                                                                                      
*/

  void Diamond::SetFill(const char fillchar)
{
  if(validchar(fillchar))   
       fill = fillchar;
  else fill = DEFAULTFILL; 
}

/*************************************************************************************************************************************************************/
/*                                                                       Summary Function                                                                    */
/*

Author: Claudius Christian 
Date: 1/13/2013 

Description: Print the summary information of the diamond which is the size, the permimeter, the area and draw the diamond. This is done by calling the 
appropriate routines.            

Parameter Description: none                                   
*/  

  void Diamond::Summary()
{
  cout << "The Diamond size is " << GetSize() << endl;
  cout << "The perimeter is " << Perimeter() << endl;
  cout << "The area is " << Area() << endl;
  Draw();
}

