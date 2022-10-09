//Include c standard library
#include <cstdlib>
//Use this for ease of programming
using namespace std;

private:
	//Set private member variables
	string position;
	string eggs;
	string bread;
	string contents["eggs","bread","things"];

public:
	
	//fragileBag member function checks if storeBag contains eggs or bread
	//If eggs or bread are contained in store Bag, sequentially remove from storeBag
	//and add to fragileBag
	void Bag::fragileBag(){
		if(storeBag.contains("eggs") || storeBag.contains("bread")){
		
			while(storeBag.contains("eggs")){
				storeBag.remove("eggs");
				fragileBag.add("eggs");
			}
			
			while(storeBag.contains("bread")){
				storeBag.remove("bread");
				fragileBag.add("bread");
			}
		}	
	}
	
	//groceryBag member function checks if storeBag does not contains eggs or bread
	//If eggs or bread are not contained in store Bag, sequentially remove contents from storeBag
	//and add to groceryBag
	void Bag::grocerybag(){
		if(storeBag.doesNotContain("eggs") || storeBag.doesNotContain("bread")){
			
			for(i = 0; contents[i] < contents[3]; contents[i++]){
				storeBag.remove(contents);
				groceryBag.add(contents);
			}
		}
		
		else(){
			cout << "Eggs and Bread have NOT been seperated out";
		}
	}
	
	/*NAH
	//Define storeBag
	void Bag::storeBag(){
		while(getBagPosition("store")){
			setBag(storeBag);
		}
	}
	
	//Set the bag to its respective bag object
	Bag Bag::setBag(Bag b){
		Bag = b;
	}
	
	//Get bag 
	string Bag::getBagPosition(){
		return position;
	}
	*/
