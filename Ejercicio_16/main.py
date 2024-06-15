from fastapi import FastAPI
from pydantic import BaseModel
from pymongo import MongoClient

app = FastAPI()

# Conexión a MongoDB
client = MongoClient('localhost', 27017)
db = client['POO']  # Base de datos POO
collection = db['Usuarios']  # Colección Usuarios

# Definir un modelo de datos para el usuario
class User(BaseModel):
    nombre: str
    apellido: str
    usuario: str
    clave: str

# Endpoint para validar usuarios
@app.post("/validate_user")
async def validate_user(usuario: str, clave: str):
    # Buscar el usuario en MongoDB
    user = collection.find_one({"usuario": usuario, "clave": clave})
    if user:
        return {"nombre": user["nombre"], "apellido": user["apellido"]}
    else:
        return {"mensaje": "denegado"}
