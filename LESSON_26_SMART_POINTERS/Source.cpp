/*SMART_POINTERS_1_ESSENTIAL_COMPONENTS*/
/*template <typename T>
class smart_pointer
{
private:
	T* rawPtr;
public: 
	smart_pointer(T* pData) : rawPtr(pData) {} //constructor
	~smart_pointer () { delete rawPtr; };	   //destructor

	//copy constructor
	smart_pointer (const smart_pointer& anotherSP);
	//copy assignment operator
	smart_pointer& operator= (const smart_pointer& anotherSP);

	T& operator* () const //dereferencing operator
	{
		return *(rawPtr);
	}

	T* operator-> () const  //member selection operator
	{
		return rawPtr;
	}
};*/

/*SMART_POINTERS_2_DEEP_COPY*/
/*template <typename T> 
class deepcopy_smart_ptr
{
private:
	T* object;
public: 
	//... other functions

	//copy constructor of the deepcopy pointer
	deepcopy_smart_ptr(const deepcopy_smart_ptr& source)
	{
		// Clone() is virtual: ensures deep copy of derived class object 
		object = source->Clone();
	}

	//copy assignment operator 
	deepcopy_smart_ptr& operator= (const deepcopy_smart_ptr& source)
	{
		if (object)
			delete obejct;

		object = source->Clone(); 
	}
};*/

/*SMART_POINTERS_3_DESTRUCTIVE_COPY_SMART_POINTER*/
/*template <typename T>
class destructivecopy_ptr
{
private:
	T* object;
public:
	destructivecopy_ptr(T* input) :object(input) {}
	~destructivecopy_ptr() { delete object; }

	//copy constructor
	destructivecopy_ptr(destructivecopy_ptr& source)
	{
		//Take ownership on copy 
		object = source.object;

		//destroy source
		source.object = 0;
	}

	//copy assignment operator 
	destructivecopy_ptr& operator= (destructivecopy_ptr& source)
	{
		if (object != source.object)
		{
			delete object;
			object = source.object;
			source.object = 0; 
		}
	}
};

int main()
{
	destructivecopy_ptr<int> num(new int);
	destructivecopy_ptr<int> copy = num;

	//num is now invalid
	return 0; 
}*/

/*SMART_POINTERS_4_UNIQUE_PTR*/
#include <iostream> 
#include <memory> //include this to use std::unique_ptr
using namespace std; 

class Fish
{
public: 
	Fish() { cout << "Fish: Constructed!" << "\n";}
	~Fish() { cout << "Fish: Destructed!" << "\n";}

	void Swim() const { cout << "Fish swims in water" << "\n";}
};

void MakeFishSwim(const unique_ptr<Fish>& inFish)
{
	inFish->Swim();
}
int main()
{
	unique_ptr<Fish> smartFish(new Fish);

	smartFish->Swim();
	MakeFishSwim(smartFish); //OK, as MakeFishSwim accepts reference 

	unique_ptr<Fish> copySmartFish;
	// copySmartFish = smartFish; // error: operator= is private

	return 0;
}