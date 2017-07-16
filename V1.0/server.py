#very basic bottle get/post

from bottle import *
import json

#post temperature
app=Bottle()
temperatureData=[{"temperature": "22.4" }, {"temperature": "21.8" }]

@app.post("/data")
def receive_data():
    data = request.body.read()
    temperatureData.append(data)
    print(data)
    return(temperatureData)

#get all data
@app.get("/getdata")
def send_data():
    response.content_type = 'application/json'
    return(json.dumps(temperatureData))
    

run(app, host='localhost', port=8080, debug=True)


    


