#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int	_index;
		int	_totalContacts;

		
	public:
		PhoneBook();
		~PhoneBook();
		void	searchContact(void);
		void	addContact(void);
		void	printTable()const;
		void	printDetails(int index)const;
};

#endif
