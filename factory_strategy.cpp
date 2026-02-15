#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class cookingStrategy
{
    public:
    virtual void cook()=0;

};
class oven:public cookingStrategy
{
   public:
   void cook()
   {
    cout<<"oven cooking \n";
   }
};
class woodfire:public cookingStrategy
{
   public:
   void cook()
   {
    cout<<"woodfire cooking \n";
   }
};
class pizza
{
protected:
    cookingStrategy* l_cookingstrategy;
    public:
    pizza(cookingStrategy*s):l_cookingstrategy(s){}
    virtual void prepare()=0;
};
class margharita:public pizza
{
    public:
    margharita(cookingStrategy*s):pizza(s){}
    void prepare()
    {
        cout<<"preparing margharita \n";
        l_cookingstrategy->cook();
    }
};
class pepporini:public pizza
{
    public:
    pepporini(cookingStrategy*s):pizza(s){}
    void prepare()
    {
        cout<<"preparing pepporini \n";
        l_cookingstrategy->cook();
    }
};
class cookingStyle
{
public:
static cookingStrategy* get_cooking_style(string style)
{
    if(style=="oven")
    return new oven();
    return new woodfire();
}
};
class pizzafactory 
{
    
    public:
    static pizza* create_pizza(string s,string style)
    {
        cookingStrategy *l_style=cookingStyle::get_cooking_style(style);
        // cookingStrategy* l_oven=new oven();
        // cookingStrategy* l_wood=new woodfire();
       
        if(s=="margharita")
        return new margharita(l_style);
        return new pepporini(l_style);


    }

};
int main()
{
    string pizza_type,cooking_style;
    cout<<"enter pizza type\n";
    cin>>pizza_type;
    cout<<"cooking style\n";
    cin>>cooking_style;
    pizza* l_pizza=pizzafactory::create_pizza(pizza_type,cooking_style);
    l_pizza->prepare();


return 0;
}