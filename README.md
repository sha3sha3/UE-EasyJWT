# Supported Platforms

![Windows](https://drive.google.com/uc?export=view&id=1k4dinqYcmrCpQ6b08JMJujBICzzTJOeo) ![Linux](https://drive.google.com/uc?export=view&id=1QwyMFHBC9qPJatMq7eUqh7m15mOkR1Hn) 

# Features

JWT Plugin provide a c++ and Blueprint support of JWT for UE4, You can easily:
```
1. Generate JWT Token
2. Verify JWT Token
3. Extract JWT Token Claims
```

## JWTPlugin Blueprint Functions
![Blueprints](https://drive.google.com/uc?export=view&id=13Dw1zaSeh_afz5olYeUqB4qsD7ELR-5q)

>Get Claims: 
Input JWTToken FString token
, Output TMap<FString,FString> Key,Value

>Create JWT Verifier:
>Input Key FString Signing key
>, Algorithm UENUM Algorith
>, Output JWT Verifier Object ref

>Create JWT Generator:
>Output JWT Generator Object ref
## Verify Token
![Verify](https://drive.google.com/uc?export=view&id=1ZqpHYhtFEcCJO3ZDrUZUXR8j9TJZ2o2k)

JWT Verifier object has a bunch of useful blueprints for claims verification and leeway

![Verifier](https://drive.google.com/uc?export=view&id=1CsFHpj7O4cDQQooi7Bh_P8LnJ8V4HmzI)

## Generate JWT Token

![Generate](https://drive.google.com/uc?export=view&id=1fx61BD-7iWLhX4DrPMErN1sA5gR4I5qT)

JWT Generator Has a lot of methods to add claims, time (iat,nbf,exp), and headers

![Generator](https://drive.google.com/uc?export=view&id=1ftVYAadjElVqfNhnlSN4drokVHhbpUdl)


## Supported Algorithms

 - HS256
 - HS348
 - HS512
 - RS256
 - RS384
 - RS512

More to come soon!!


