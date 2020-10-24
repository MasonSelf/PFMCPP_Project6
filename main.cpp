/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* homeSlice) :   //1
    value(v),                           //2
    name(homeSlice)                        //3
    {}
    int value;
    std::string name;
};

struct Pajamas                                //4
{
    T* compare(T& a, T& b)                  //5
    {
        if ( a != nullptr && b != nullptr)
        {
            if( &a.value < &b.value ) return &a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float crown { 0.f }, jewel { 0.f };
    float altMorph(float* updatedAccessories)      //12
    {
        if (updatedAccessories != nullptr)
        { 
            std::cout << "U's crown value: " << this->crown << std::endl;
            this->crown = *updatedAccessories;
            std::cout << "U's crown updated value: " << this->crown << std::endl;
            while( std::abs(this->crown - this->jewel) > 0.001f )
            {
                this->jewel += (this->crown - this->jewel) / 1000.f ;
            }
            std::cout << "U's jewel updated value: " << this->jewel << std::endl;
        }
        else 
        {
            std::cout << "nullptr alert! returning jewel * crown (not updated)..." << std::endl;  
        }
        return this->jewel * this->crown; 
    }
};

struct Hope
{
    static float crownJewelMorph(U* that, float* updatedAccessories )        //10
    {
        if ( that != nullptr && updatedAccessories != nullptr)
        {
            std::cout << "U's crown value: " << that->crown << std::endl;
            that->crown = *updatedAccessories;
            std::cout << "U's crown updated value: " << that->crown << std::endl;
            while( std::abs(that->crown - that->jewel) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that->jewel += (that->crown - that->jewel) / 1000.f ;
            }
            std::cout << "U's jewel updated value: " << that->jewel << std::endl;
            return that->jewel * that->crown;
        }
        std::cout << "one or both arguments is nullptr! returning 0.f" << std::endl;
        return 0.f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T digniT( 0, "dignity" );                           //6
    T prosperiT( 1, "prosperity" );                     //6
    
    Pajamas f;                                                          //7
    auto* smaller = f.compare( &digniT , &prosperiT );                   //8
    if ( smaller != nullptr )
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U Sun;
    float updatedValue = 5.f;
    std::cout << "[static func] Sun's multiplied values: " << Hope::crownJewelMorph( &Sun , &updatedValue ) << std::endl;                  //11
    
    U Moon;
    std::cout << "[member func] Moon's multiplied values: " << Moon.altMorph( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
