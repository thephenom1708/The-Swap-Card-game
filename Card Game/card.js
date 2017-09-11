
function assign()
{
	 if(x.nm===1)
    {
	    $("#a").each(function(){
    		$(this).attr("src","deck\\heart\\h"+x.val+".png");
    	});
	}
	if(x.nm===2)
    {
	    $("#a").each(function(){
    		$(this).attr("src","deck\\diamond\\d"+x.val+".png");
    	});
	}
	if(x.nm===3)
    {
	    $("#a").each(function(){
    		$(this).attr("src","deck\\club\\c"+x.val+".png");
    	});
	}
	if(x.nm===4)
    {
	    $("#a").each(function(){
    		$(this).attr("src","deck\\spade\\s"+x.val+".png");
    	});
	}


	 if(y.nm===1)
    {
	    $("#b").each(function(){
    		$(this).attr("src","deck\\heart\\h"+y.val+".png");
    	});
	}
	if(y.nm===2)
    {
	    $("#b").each(function(){
    		$(this).attr("src","deck\\diamond\\d"+y.val+".png");
    	});
	}
	if(y.nm===3)
    {
	    $("#b").each(function(){
    		$(this).attr("src","deck\\club\\c"+y.val+".png");
    	});
	}
	if(y.nm===4)
    {
	    $("#b").each(function(){
    		$(this).attr("src","deck\\spade\\s"+y.val+".png");
    	});
	}


	 if(z.nm===1)
    {
	    $("#c").each(function(){
    		$(this).attr("src","deck\\heart\\h"+z.val+".png");
    	});
	}
	if(z.nm===2)
    {
	    $("#c").each(function(){
    		$(this).attr("src","deck\\diamond\\d"+z.val+".png");
    	});
	}
	if(z.nm===3)
    {
	    $("#c").each(function(){
    		$(this).attr("src","deck\\club\\c"+z.val+".png");
    	});
	}
	if(z.nm===4)
    {
	    $("#c").each(function(){
    		$(this).attr("src","deck\\spade\\s"+z.val+".png");
    	});
	}

}

 $(document).ready(function(){
            $("#con1").hide();
        });
  $(document).ready(function(){
            $("#con3").hide();
        });
 
    var btn=document.getElementById("btn");
    btn.onclick=function()
     {
        $(document).ready(function(){
            $("#con1").show(1000);
        });
      }

      var show=document.getElementById("show");
      var a1=document.getElementById("a");
      var b1=document.getElementById("b");
      var c1=document.getElementById("c");

      var x={val:Math.floor((Math.random()*13)+1),nm:Math.floor((Math.random()*4)+1)}; 
      var y={val:Math.floor((Math.random()*13)+1),nm:Math.floor((Math.random()*4)+1)};
      var z={val:Math.floor((Math.random()*13)+1),nm:Math.floor((Math.random()*4)+1)};
    	
      show.onclick=function()
      {
      	assign();

        $(document).ready(function(){
            $(".start").hide();
        });

        $(document).ready(function(){
            $("#con1").hide();
        });

        $(document).ready(function(){
            $("#con2").show(1000);
        });
 /*document.getElementById("print").innerHTML=x.val+" "+y.val+" "+z.val;*/

	}
 
      var swap2=document.getElementById("swap2");

      swap2.onclick=function()
      {
      		var d;
            d=Math.floor((Math.random()*100)+1);
            var t={val:Math.floor((Math.random()*13)+1),nm:Math.floor((Math.random()*4)+1)};
            for(var i=0; i<d; i++)
            {
              t=x;
              x=y;
              y=z;
              z=t;
            } 
            assign();
	        $(document).ready(function(){
	            $("#con2").hide();
	        });
	       $(document).ready(function(){
	            $("#con3").show(1000);
	        });
	            
	    	/*$(document).ready(function(){
	            $("#con2").show();
	        });*/
/*document.getElementById("print").innerHTML=x.val+" "+y.val+" "+z.val+" "+x1+" "+y1+" "+z1;*/
      }
      var submit=document.getElementById("sub");
      var x1,y1,z1;
      if(x.nm==1)
      {
      	x1="Heart";
      }
       if(x.nm==2)
      {
      	x1="Diamond";
      }
       if(x.nm==3)
      {
      	x1="Club";
      }
       if(x.nm==4)
      {
      	x1="Spade";
      }

       if(y.nm==1)
      {
      	y1="Heart";
      }
       if(y.nm==2)
      {
      	y1="Diamond";
      }
       if(y.nm==3)
      {
      	y1="Club";
      }
       if(y.nm==4)
      {
      	y1="Spade";
      }

       if(z.nm==1)
      {
      	z1="Heart";
      }
       if(z.nm==2)
      {
      	z1="Diamond";
      }
       if(z.nm==3)
      {
      	z1="Club";
      }
       if(z.nm==4)
      {
      	z1="Spade";
      }
      submit.onclick=function()
      {
		var g1=document.getElementById("g1").value;
		var g2=document.getElementById("g2").value;
		var g3=document.getElementById("g3").value;
		var g4=document.getElementById("nm1").value;
		var g5=document.getElementById("nm2").value;
		var g6=document.getElementById("nm3").value;

		if(g1==x.val && g2==y.val && g3==z.val && g4==x1 && g5==y1 && g6==z1)
		{
			document.getElementById("print").innerHTML="YOU WIN!!!!";
		}
		else
		{
			document.getElementById("print").innerHTML="TRY AGAIN!!!";
		}
      }
     