class Doctor:
    def __init__(self,doctorId,doctorName,specialization,consultationFee):
        self.doctorId=doctorId
        self.doctorName=doctorName
        self.specialization=specialization
        self.consultationFee=consultationFee

class Hospital:
    def __init__(self,doctorDB):
        self.doctorDB=doctorDB
    
    def searchByDoctorName(self,doc_name):
        list_matches=[]
        for i in self.doctorDB.keys():
            if self.doctorDB[i].doctorName==doc_name:
                list_matches=list_matches+[self.doctorDB[i]]
        return list_matches

            

    def calculateConsultationFeeBySpecialization(self,doc_spec):
        fees=0
        for i in self.doctorDB.keys():
            if self.doctorDB[i].specialization==doc_spec:
                fees=fees+self.doctorDB[i].consultationFee

        return fees



if __name__=="__main__":
    n=int(input("No of doctor in the clinic: "))
    lis=[]
    for j in range(n):
        doctorId=int(input(f"{j+1} no. doctors id: "))
        doctorName=input(f"{j+1} no. Doctor's name: ")
        specialization=input(f"{j+1} no. Doctor's specialization: ")
        consultationFee=int(input(f"{j+1} no. Doctor's consultation fee: "))
        obj=[Doctor(doctorId,doctorName,specialization,consultationFee)]
        lis=lis+obj

    doctorDB={}
    c=1
    for k in lis:
        doctorDB[c]=k
        c=c+1 
    hospital=Hospital(doctorDB)
    search_doc_name=input("Give the doctor's name to know the info: ")
    search_by_spec=input("Give your required specification: ")
    
    doctor_info=hospital.searchByDoctorName(search_doc_name)
    if len(doctor_info)==0:
        print("No Doctor Exists with the given DoctorName")
    else:
        for i in doctor_info:
            print(i.doctorId)
            print(i.doctorName)
            print(i.specialization)
            print(i.consultationFee)
        

    fee=hospital.calculateConsultationFeeBySpecialization(search_by_spec)
    if fee==0:
        print("No Doctor with the given specialization")
    else:
        print(fee)