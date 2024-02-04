#include "TextBook.h"

int main() {
	TextBook book(2);
	char ct2[206] = "Sed nec erat vitae leo \nfaucibus viverra nec vitae nulla.\n Nulla facilisi. Sed suscipit luctus neque, quis pulvinar eros porta ac. \nMaecenas mollis odio purus, \nid interdum magna \ntristique ut dapibus nam";
	book.addText(new ArgumentText<int>("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam pulvinar semper ipsum, nec efficitur", 25, 25 , 25, 25, 3));
	Poem poem(ct2, 3);
	poem.addKeyWord("potatoes");
	poem.addKeyWord("soup");
	poem.addKeyWord("and cola");
	book.addText(&poem);
	std::cout << book;
}