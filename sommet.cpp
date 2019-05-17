#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(std::string id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}

void Sommet::ajouterVoisin(const Sommet* voisin)
{
    m_voisins.push_back(voisin);
}
void Sommet::afficherData() const
{
    std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}

void Sommet::afficherVoisins()const
{
    std::cout<<"voisins :"<<std::endl;
    for(auto v:m_voisins)
    {
        v->afficherData();
    }
    std::cout<<std::endl;
}

std::unordered_map<std::string,std::string> Sommet::parcoursBFS() const
{
    std::unordered_map<std::string,std::string> l_pred;
    std::unordered_set<std::string> l_marque;
    std::queue<const Sommet*> file;

    file.push(this);
    l_marque.insert(this->m_id);

    while(!file.empty())
    {
        for (auto elem : file.front()->m_voisins)
        {
            if ( l_marque.find(elem->m_id) == l_marque.end() )
            {
                l_marque.insert(elem->m_id);
                l_pred.insert({elem->m_id,file.front()->m_id});
                file.push(elem);
            }
        }
        file.pop();
    }
    return l_pred;
}

std::unordered_map<std::string,std::string> Sommet::parcoursDFS() const
{

    std::unordered_map<std::string,std::string> l_pred;
    std::unordered_set<std::string> l_marque;
    std::stack<const Sommet*> pile;

    pile.push(this);
    l_marque.insert(this->m_id);
    Sommet courant;

    while(!pile.empty())
    {
        courant = *(pile.top()) ;
        pile.pop();
        for (auto elem : courant.m_voisins)
        {
            if (l_marque.find(elem->m_id) == l_marque.end())
            {
                pile.push(elem);
                l_marque.insert(elem->m_id);
                l_pred.insert({elem->m_id,courant.m_id});
            }
        }
    }
    return l_pred;
}

std::unordered_set<std::string> Sommet::rechercherCC ( ) const
{
    std::unordered_set<std::string> cc;
    std::stack<const Sommet*> pile;
    pile.push(this);
    cc.insert(m_id);

    while (!pile.empty())
    {
        const Sommet* courant = pile.top();
        pile.pop();
        for ( const auto& elem : courant->m_voisins )
        {
            if ( cc.find ( elem->m_id ) == cc.end ( ) )
            {
                cc.insert ( elem->m_id );
                pile.push ( elem );
            }
        }
    }
    return cc;
}
Sommet::~Sommet()
{
    //dtor
}
Sommet::Sommet()
{
    //dsv
}
