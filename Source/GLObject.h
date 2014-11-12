#ifndef ___OGL2D_OBJECT_H___
#define ___OGL2D_OBJECT_H___

#include "OpenGL2DPrerequisites.h"
#include <cassert>
#include <functional>

namespace GL2D
{
	//! Fonction de cr�ation d'identificateur OpenGL.
	typedef std::function< void ( GLsizei, GLuint * ) > Ctor;
	//! Fonction de destruction d'identificateur OpenGL.
	typedef std::function< void ( GLsizei, const GLuint * ) > Dtor;
	
	/*!
	\author 	Sylvain DOREMUS
	\brief		G�re l'identificateur OpenGL d'un objet.
	*/
	class CObject
	{
	public:
		/** Constructeur
		@param ctor
			Fonction de cr�ation de l'identificateur.
		 @param dtor
			Fonction de destruction de l'identificateur.
		*/
		GL2D_API CObject()
			: m_name( GL_INVALID_INDEX )
			, m_ctor()
			, m_dtor()
		{
		}

		/** Destructeur
		*/
		GL2D_API virtual ~CObject()
		{
			assert( m_name == GL_INVALID_INDEX );
		}

		/** Cr�e l'identificateur OpenGL.
		@return
			\p true si tout s'est bien pass�.
		*/
		GL2D_API STDMETHOD( Initialise )( Ctor ctor, Dtor dtor )
		{
			m_ctor = ctor;
			m_dtor = dtor;
			m_ctor( 1, &m_name );
			assert( m_name != GL_INVALID_INDEX );
			return m_name != GL_INVALID_INDEX ? S_OK : E_FAIL;
		}

		/** D�truit l'identificateur OpenGL.
		*/
		GL2D_API STDMETHOD_( void, Cleanup )()
		{
			m_dtor( 1, &m_name );
			m_name = GL_INVALID_INDEX;
		}

		/** R�cup�re l'identificateur OpenGL.
		@return
			L'identificateur.
		*/
		GL2D_API STDMETHOD_( GLuint, GetName )()
		{
			return m_name;
		}

	private:
		//! Fonction de cr�ation de l'identificateur.
		Ctor m_ctor;
		//! Fonction de destruction de l'identificateur.
		Dtor m_dtor;

	protected:
		//! L'identificateur OpenGL.
		GLuint m_name;
	};
}

#endif
