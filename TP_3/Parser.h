#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

////////////////////////////////////////////////////////////////////////////////////
/////////////        parser_EmployeeFromText     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Parses a text file and add the employees in a linked list
*
*\param pFile pointer to the file
*\param pArrayListEmployee pointer to the linked list
*\return 0 is file was loaded correctly, -1 if there was an error during the reading
*
*/
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

////////////////////////////////////////////////////////////////////////////////////
///////////        parser_EmployeeFromBinary     ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

/** \brief Parses a bin file and add the employees in a linked list
*
*\param pFile pointer to the file
*\param pArrayListEmployee pointer to the linked list
*\return 0 is file was loaded correctly, -1 if there was an error during the reading
*
*/
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // parser_H_INCLUDED
