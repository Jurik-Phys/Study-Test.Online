import style from './AdminSessionsView.module.css'
import { useNavigate, useParams } from "react-router-dom"
import { useEffect, useState } from "react"
import axios from 'axios';


const printChallengesData = (data) => {
  return (
    <>
      {
        data.map((item, index) => {
          return (
            <div>
              <label className={style.sText}>
                {index + 1}. {item.section}
              </label>
              <div style={{ marginLeft: '1.75em' }}>
              {
                item["subsection"].map( (subsection) =>{
                  return (
                    <div>
                      {subsection}
                    </div>
                  )
                  }
                )
              }
              <div>
                <label className={style.sText}>
                  Аннотация.
                </label> {item.annotation}
              </div>
              <div>
                <label className={style.sText}>
                  Количество вопросов:
                </label> {item.totalQuestions}
              </div>
              <div>
                <label className={style.sText}>
                  Время выполнения:
                </label> {item.maxTime} мин.
              </div>
              <div>
                - - -
              </div>
              </div>
            </div>
          )}
        )
      }
    </>
  )
}

const AdminSessionsView = () => {
  const [loading, setLoading] = useState(true);
  const navigate = useNavigate();
  const { testTypeId } = useParams();
  const [challengesData, setChallengesData] = useState(null)

  useEffect( () => {
    const fetchData = async () => {
    try {
      const response = await axios.get('http://localhost:7500/challenges');
      const dataAPI = response.data
      const challenges = dataAPI.filter(item => item.testType === testTypeId);
      if (challenges !== null && challenges !== undefined && challenges.length !== 0){
        const oldObj = JSON.stringify(challengesData)
        const newObj = JSON.stringify(challenges)
        if ( oldObj !== newObj){
          setChallengesData(challenges)
        }
        setLoading(false)
      }
    }
    catch (error) {
      console.error('Error fetching data:', error);
      }
    };

  fetchData();
  }, [challengesData, testTypeId])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  return (
      <div className={style.bodyStyle}>
          <div className={style.hText}>
            <div>Список испытаний</div>
            <div>dev: read-only</div>
          </div>
        <div className={style.text}>
          <div style={{ width: '40vw', height: '48vh', overflow: 'auto', border: '0px solid gray' }} >
          {printChallengesData(challengesData) }
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate(-1)} >Back</button>
        </div>
      </div>
  );
}

export default AdminSessionsView;
