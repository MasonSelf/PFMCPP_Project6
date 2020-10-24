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
    T(int v, const char* homeSlice) :   
    value(v),                           
    name(homeSlice)                        
    {}
    int value;
    std::string name;
};

struct Pajamas                                
{
    T* compare(T& a, T& b)                  
    {
        if( a.value < b.value ) 
            return &a;
        if( a.value > b.value ) 
            return &b;
        return nullptr;
    }
};

struct U
{
    float crown { 0.f }, jewel { 0.f };
    float altMorph(float& updatedAccessories)      
    {
        std::cout << "U's crown value: " << crown << std::endl;
        crown = updatedAccessories;
        std::cout << "U's crown updated value: " << crown << std::endl;
        while( std::abs(crown - jewel) > 0.001f )
        {
            jewel += (crown - jewel) / 1000.f ;
        }
        std::cout << "U's jewel updated value: " << jewel << std::endl;
        return jewel * crown; 
    }
};

struct Hope
{
    static float crownJewelMorph(U& that, float& updatedAccessories )        
    {
        std::cout << "U's crown value: " << that.crown << std::endl;
        that.crown = updatedAccessories;
        std::cout << "U's crown updated value: " << that.crown << std::endl;
        while( std::abs(that.crown - that.jewel) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.jewel += (that.crown - that.jewel) / 1000.f ;
        }
        std::cout << "U's jewel updated value: " << that.jewel << std::endl;
        return that.jewel * that.crown;
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
    T digniT( 0, "dignity" );                           
    T prosperiT( 1, "prosperity" );                     
    
    Pajamas f;                                                          
    auto smaller = f.compare( digniT , prosperiT );         
    if ( smaller != nullptr )
    {          
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }
    U sun;
    float updatedValue = 5.f;
    std::cout << "[static func] Sun's multiplied values: " << Hope::crownJewelMorph( sun , updatedValue ) << std::endl;                  
    
    U moon;
    std::cout << "[member func] Moon's multiplied values: " << moon.altMorph( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
