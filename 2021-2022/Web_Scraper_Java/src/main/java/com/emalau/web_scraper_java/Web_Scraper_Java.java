
package com.emalau.web_scraper_java;



public class Web_Scraper_Java {

    public static void main(String[] args){
        Document doc = Jsoup.connect("http://example.com")
            .data("query", "Java")
            .userAgent("Mozilla")
            .cookie("auth", "token")
            .timeout(3000)
            .post();
    }
}
