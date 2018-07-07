ctx = document.getElementById("example").getContext('2d');
cs = document.getElementById("step").getContext('2d');			    
dv = document.getElementById('win');                  
dvWin = document.getElementById('score');                    
                            var painted = [];
                            winCross =0;
                            winCircle =0;
                    function start(){
                            dv.innerHTML = '';
                            paintDiv ="00";
                            paintCross = true;
                           
                           for(i=0;i<3;i++){
                               painted[i] =[];
                               for(j=0;j<3;j++)
                                   painted[i][j] = 0;
                           }
                            ctx.clearRect(0,0,600,600);
                        ctx.beginPath();
                        ctx.strokeStyle = "black";
                        ctx.lineWidth =1;
			ctx.moveTo(200,0);
                        ctx.lineTo(200,600);    
                        ctx.moveTo(400,0);
                        ctx.lineTo(400,600);
                        ctx.moveTo(0,200);
                        ctx.lineTo(600,200);
                        ctx.moveTo(0,400);
                        ctx.lineTo(600,400);
                        
                        ctx.moveTo(0,0);
                        ctx.lineTo(0,600);
                        
                        ctx.moveTo(0,0);
                        ctx.lineTo(600,0);
                        
                        ctx.moveTo(600,0);
                        ctx.lineTo(600,600);
                        
                        ctx.moveTo(600,600);
                        ctx.lineTo(0,600);
                        
                        
                        
                        ctx.stroke();
                        ctx.closePath();
                        
                        
                        currentStep(paintCross);
                    }
                    
                        function  f  (e){
                            if ((e.clientX <200) && (e.clientY <200))
                                paintDiv="00";
                            else
                            if ((e.clientX <400) && (e.clientY <200))
                                paintDiv="10";
                        else
                            if ((e.clientX <600) && (e.clientY <200))
                                paintDiv="20";
                        else
                            if ((e.clientX <200) && (e.clientY <400))
                               paintDiv="01";
                            else
                            if ((e.clientX <400) && (e.clientY <400))
                               paintDiv="11";
                        else
                            if ((e.clientX <600) && (e.clientY <400))
                               paintDiv="21";
                        else
                        if ((e.clientX <200) && (e.clientY <600))
                                paintDiv="02";
                        else
                            if ((e.clientX <400) && (e.clientY <600))
                                paintDiv="12";
                        else
                            if ((e.clientX <600) && (e.clientY <600))
                               paintDiv="22";
                       if(painted[paintDiv[0]][paintDiv[1]] == 0)
                       {
                           if(paintCross)
                        painted[paintDiv[0]][paintDiv[1]] = 1;
                            else
                        painted[paintDiv[0]][paintDiv[1]] = 2;
                        
                        Paint(paintDiv,paintCross);
                        paintCross = !paintCross;
                        currentStep(paintCross);
                    //    if (!paintCross)
                      //  II();
                        }
                    }
                        function paint(paintDiv,paintCross){
                            if(paintCross){
                            ctx.beginPath();
                            ctx.strokeStyle="blue";
                            ctx.lineWidth =5;
                            ctx.moveTo(0+200*paintDiv[0],0+200*paintDiv[1]);
                            ctx.lineTo(200+200*paintDiv[0],200+200*paintDiv[1]);
                            ctx.moveTo(0+200*paintDiv[0],200+200*paintDiv[1]);
                            ctx.lineTo(200+200*paintDiv[0],0+200*paintDiv[1]);
                            ctx.stroke();
                            ctx.closePath();
                        }
                            else{                               
                                    ctx.beginPath(); 
                                    ctx.strokeStyle="red";
                                    ctx.lineWidth =5;
                                    ctx.arc(100+200*paintDiv[0], 100+200*paintDiv[1], 95, 0, Math.PI*2, false); 
                                    ctx.stroke(); 
                                    ctx.closePath(); 

                            }
                           x = check();
                           if(x!=0)
                               drawWinLine(x);
                               
                           
                                
                        }
                        
     function check(){
     if ((painted[0][0] != 0) && (painted[0][0] == painted[0][1]) && (painted[0][0] == painted[0][2])){
         writeWinner(painted[0][0]);
         return "0002";
     }
     
     else
     if ((painted[1][0] != 0) && (painted[1][0] == painted[1][1]) && (painted[1][0] == painted[1][2]))
 {
         writeWinner(painted[1][0]);
         return "1012";
     }
     
 else
     if ((painted[2][0] != 0) && (painted[2][0] == painted[2][1]) && (painted[2][0] == painted[2][2])){
         writeWinner(painted[2][0]);
         return "2022";
     }
 else
     if ((painted[0][0] != 0) && (painted[0][0] == painted[1][0]) && (painted[0][0] == painted[2][0])){
         writeWinner(painted[0][0]);
         return "0020";
     }
 else
     if ((painted[0][1] != 0) && (painted[0][1] == painted[1][1]) && (painted[1][1] == painted[2][1])){
         writeWinner(painted[0][1]);
         return "0121";
     }
 else
     if ((painted[0][2] != 0) && (painted[0][2] == painted[1][2]) && (painted[0][2] == painted[2][2])){
         writeWinner(painted[0][2]);
         return "0222";
     }
 else
     if ((painted[0][0] != 0) && (painted[0][0] == painted[1][1]) && (painted[0][0] == painted[2][2])){
         writeWinner(painted[0][0]);
         return "0022";
     }
 else
     if ((painted[2][0] != 0) && (painted[2][0] == painted[1][1]) && (painted[2][0] == painted[0][2]))        {
         writeWinner(painted[2][0]);
         return "2002";
     }
     return "0";
}

function drawWinLine(coordBE){
    ctx.beginPath();
    ctx.lineWidth = 10;
    if((coordBE == "0022") || (coordBE == "2002")){
           ctx.moveTo(300*coordBE[0],0);
            ctx.lineTo(300*coordBE[2],600);
    } 
    else
        if((coordBE[0] == 0) && (coordBE[2] == 2)){ 
    ctx.moveTo(0,100+200*coordBE[1]);
    ctx.lineTo(600,100+200*coordBE[3]);
}
    else
        if((coordBE[1] == 0 ) && (coordBE[3] == 2 )){
            ctx.moveTo(100+200*coordBE[0],0);
            ctx.lineTo(100+200*coordBE[2],600);
        }
         
    ctx.stroke();
    ctx.closePath();
    
                            for(i=0;i<3;i++){
                               for(j=0;j<3;j++)
                                   painted[i][j] = 1;
                           }
                           
                           
    
}
function writeWinner(player){
    if(player== 1){
        dv.style.color = "blue";
        
        dv.innerHTML = "Победил крестик!";
        winCross++;
        
        dvWin.style.color = "blue";
        
        
    }
    else{
        dv.style.color="red";       
        dv.innerHTML = "Победил нолик!";
        winCircle++;
        if (winCross < winCircle)
        dvWin.style.color = "red";
    }
    dvWin.innerHTML = "K-" + winCross + ":" + winCircle + "-Н";
    
}

function currentStep(paintCross){
    cs.clearRect(0,0,150,300);
    if(paintCross){
                            cs.beginPath();
                            cs.strokeStyle = "blue";
                            cs.lineWidth =3;
                            cs.moveTo(0,0);
                            cs.lineTo(150,150);
                            cs.moveTo(150,0);
                            cs.lineTo(0,150);
                            cs.stroke();
                            cs.closePath();
                        }
                            else{                               
                                    cs.beginPath(); 
                                    cs.strokeStyle = "red";
                                    cs.lineWidth =3;
                                    cs.arc(75,225,72, 0, Math.PI*2, false); 
                                    cs.stroke(); 
                                    cs.closePath(); 

                            }
}

function clearScore(){
    winCircle =0;
    winCross =0;
    dvWin.style.color = "black";
    dvWin.innerHTML="K-0:0-H";
}
function II(){
   /* for(i=0;i< 3;i++){
        if (i==0){
        if((painted[i][i] == 2) && (painted[i+1][i] == 2)) 
            paint("20",false);
        }
    }*/
}