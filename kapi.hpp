#ifndef _KRAKEN_KAPI_HPP_
#define _KRAKEN_KAPI_HPP_

#include <map>
#include <string>
#include <vector>
#include <curl/curl.h>

//------------------------------------------------------------------------------

namespace Kraken {

//------------------------------------------------------------------------------

class KAPI {
public:  
   // helper type to make requests
   typedef std::map<std::string,std::string> Input;

   // constructor with all explicit parameters
   KAPI(const std::string& key, const std::string& secret, 
        const std::string& url, const std::string& version);

   // default API base URL and API version
   KAPI(const std::string& key, const std::string& secret);
   
   // constructor with empty API key and API secret
   KAPI();

   // distructor
   ~KAPI();

   // makes public method to kraken.com 
   std::string public_method(const std::string& method,
			     const KAPI::Input& input) const;

   // makes private method to kraken.com
   std::string private_method(const std::string& method,
			      const KAPI::Input& input) const;

   // TODO: public market data
   //void time();
   //void assets();

private:
   // init CURL and other stuffs
   void init();

   // create signature for private requests
   std::string signature(const std::string& path,
			 const std::string& nonce,
			 const std::string& postdata) const;

   // CURL writefunction callback
   static size_t write_cb(char* ptr, size_t size, 
			  size_t nmemb, void* userdata);

   std::string key_;     // API key
   std::string secret_;  // API secret
   std::string url_;     // API base URL
   std::string version_; // API version
   CURL*  curl_;         // CURL handle
};

//------------------------------------------------------------------------------

}; // namespace Kraken

//------------------------------------------------------------------------------

#endif 


