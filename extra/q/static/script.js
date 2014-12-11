
var quoteFactory = function(){
    var makeQuotElt = function(d){
	var q = "<blockquote><p>" + d.quote + "</p></blockquote>";
	return q;
    };
    var addQuote = function(d){
	var q = makeQuotElt(d);
	$("#aquote").append(q);
    };
    var getAddQuote = function(){
	$.getJSON("/quote",function(d){
	    addQuote(d);
	});
    };
    var clearQuotes = function(){
	$("#aquote").empty();
    };
    var changeRandomQuote = function(){
	$.getJSON("/quote",function(d){
	    var q = makeQuotElt(d);
	    var elt = $("#rquote");
	    /*
	    elt.fadeOut(2000);//asynchronous 
	    elt.empty();
	    elt.append(q);
	    elt.fadeIn(2000);
	    */
	    elt.slideUp(2000, function(){
		elt.empty();
		elt.append(q);
		elt.slideDown(2000);
	    });		
	});
    };
    var interval; //public variable to hold the timer
    return {
	add : getAddQuote,
	clear : clearQuotes,
	rand : changeRandomQuote,
	interval : interval
    };
};





$(document).ready(function(){
    console.log("HELLO");
    var quotes = quoteFactory(); //quotes.add({quote: "Hello"});
    $("#add").bind("click",quotes.add);
    $("#clear").bind("click",quotes.clear);
    quotes.interval = setInterval(quotes.rand,7000);
});
