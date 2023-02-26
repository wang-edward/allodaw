#include "Track.hpp"

Track:: Track(const Track& t) {
  for (const up_Plugin p : t.mPlugins) {
    mPlugins.push_back()
  }
}

B(const B & b ) {
  for( const std::unique_ptr< A >& val: b.m_Array ) {
    m_Array.push_back( std::unique_ptr< A >( new A( *val ) ) );
  }
}

