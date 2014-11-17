//
//  File.h
//  AutoPtr
//
//  Created by cedric on 09.10.13.
//  Copyright (c) 2013 cedric. All rights reserved.
//

#ifndef __AutoPtr__File__
#define __AutoPtr__File__ 

#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
public:
    AutoPtr( T* p = 0 ) : m_pMyPtr( p ) { }
    
    AutoPtr( const AutoPtr& r ) : m_pMyPtr( r.Detach() ) { }
    
    ~AutoPtr()
    {
        delete m_pMyPtr;
    }
    
    AutoPtr& operator=( const AutoPtr& r )
    {
        if( ( void* )&r != ( void* ) this )
        {
            delete m_pMyPtr;
            m_pMyPtr = r.Detach();
        }
        return *this;
    }
    
    T& operator*() const
    {
        return *m_pMyPtr;
    }
    
    T* operator->() const
    {
        return m_pMyPtr;
    }
    
    void Free()
    {
        delete m_pMyPtr;
        m_pMyPtr = 0;
    }
    
    T* Detach() const
    {
        T* old = m_pMyPtr;
        const_cast<AutoPtr*>( this )->m_pMyPtr = 0;
        return old;
    }
    
    void Attach( T* pPtr )
    {
        m_pMyPtr = pPtr;
    }
    
private:
    T*  m_pMyPtr;
};

#endif
